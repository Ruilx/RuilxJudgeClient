#include "mainwindow.h"

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	Qt::Key key = static_cast<Qt::Key>(e->key());
	Qt::KeyboardModifiers modKey = e->modifiers();
	if((modKey == Qt::ControlModifier) && (key == Qt::Key_Enter)){
		if(this->input->isEnabled() && this->send->isEnabled()){
			this->sendClicked();
		}
	}

	QWidget::keyPressEvent(e);
}

void MainWindow::closeEvent(QCloseEvent *)
{
	if(this->net->isRunning()){
		this->net->doDisconnect();
	}
}

void MainWindow::timerEvent(QTimerEvent *)
{
	this->killTimer(this->timerId);
	this->startSystem();
}

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->resize(800, 600);
	this->output = new QTextEdit(this);
	this->output->setReadOnly(true);
	this->input = new QLineEdit(this);
	this->input->setEnabled(false);

	this->send = new QPushButton(tr("发送[&S](Ctrl+Enter)"), this);
	this->send->setEnabled(false);

	QWidget *w = new QWidget(this);
	QGridLayout *lay = new QGridLayout;
	w->setLayout(lay);
	lay->addWidget(this->output, 0, 0, 1, 2);
	lay->addWidget(this->input, 1, 0, 1, 1);
	lay->addWidget(this->send, 1, 1, 1, 1, Qt::AlignRight);

	this->setCentralWidget(w);

	connect(this->send, SIGNAL(clicked(bool)), this, SLOT(sendClicked()));

	this->showStdOut(tr("欢迎使用Ruilx Judge Client, 系统将在3秒后启动."));
	this->config = new Config("config.ini", this);
	this->timerId = this->startTimer(3000);

	this->inputHandle = new InputHandle(this);
	connect(this->inputHandle, SIGNAL(stdOut(QString)), this, SLOT(showStdOut(QString)));

	this->outputHandle = new OutputHandle(this);
	connect(this->outputHandle, SIGNAL(stdOut(QString)), this, SLOT(showStdOut(QString)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::startSystem()
{
	showStdOut(tr("正在检查配置文件"));
	ns.port = config->getNetworkPort();
	if(ns.port == 0){
		qCritical() << "Config file error: network port invaild or not defined.";
		showStdOut(tr("配置文件错误: 未找到服务器端口设置, 请正确配置config.ini文件."));
		return;
	}else{
		qInfo() << "Config: network port:" << ns.port;
		showStdOut(tr("配置: 读取网络端口: %1.").arg(ns.port));
	}

	ns.host = config->getNetworkHostName();
	if(ns.host.isEmpty()){
		qCritical() << "Config file error: network host invaild or not defined.";
		showStdOut(tr("配置文件错误: 未找到服务器地址设置, 请正确配置config.ini文件."));
		return;
	}else{
		qInfo() << "Config: network port:" << ns.port;
		showStdOut(tr("配置: 读取服务器地址: %1.").arg(ns.host));
	}

	qInfo() << "connect to server...";
	showStdOut(tr("正在连接服务器..."));
	this->net = new Network(ns.host, ns.port, this);
	connect(this->net, SIGNAL(stdOut(QString)), this, SLOT(showStdOut(QString)));
	connect(this->net, SIGNAL(connected()), this, SLOT(enableInputPanel()));
	connect(this->net, SIGNAL(disconnected()), this, SLOT(disableInputPanel()));
	if(!this->net->doConnect()){
		qCritical() << "Network error, network start failed.";
		showStdOut(tr("连接服务器失败."));
		return;
	}

	qInfo() << "Starting network communication server.";
	showStdOut(tr("启动网络处理系统..."));
	this->netC = new NetworkCommunication(this->net, this);
	connect(this->netC, SIGNAL(stdOut(QString)), this, SLOT(showStdOut(QString)));

	qInfo() << "Maybe all ready server had been checking successfully!";
	showStdOut(tr("所有子系统应该都成功启动了吧..."));

	showStdOut(tr("打开系统网络请求回复监听器..."));
	connect(this->inputHandle, SIGNAL(sendQuestionList()), this->netC, SLOT(requestQuestionList()));
	connect(this->inputHandle, SIGNAL(sendQuestionContent(int)), this->netC, SLOT(requestQuestionContent(int)));
	connect(this->inputHandle, SIGNAL(sendJudge(Judge)), this->netC, SLOT(requestJudge(Judge)));
	connect(this->inputHandle, SIGNAL(sendUserInformation(QString,QString)), this->netC, SLOT(requestUserInformation(QString,QString)));

	connect(this->netC, SIGNAL(responseQuestionList(QList<QuestionBrief>)), this->outputHandle, SLOT(receiveQuestionList(QList<QuestionBrief>)));
	connect(this->netC, SIGNAL(responseQuestionContent(Question)), this->outputHandle, SLOT(receiveQuestionContent(Question)));
	connect(this->netC, SIGNAL(responseJudge(JudgeResult)), this->outputHandle, SLOT(receiveJudge(JudgeResult)));
	connect(this->netC, SIGNAL(responseUserInformation(User)), this->outputHandle, SLOT(receiveUserInformation(User)));

	showStdOut(tr("网络请求收发器已开启."));
	showStdOut(tr("请输入命令开始执行任务..."));
}

void MainWindow::sendClicked()
{
	this->inputHandle->inputProcessor(this->input->text());
}

void MainWindow::enableInputPanel()
{
	this->input->setEnabled(true);
	this->send->setEnabled(true);
}

void MainWindow::disableInputPanel()
{
	this->input->setEnabled(false);
	this->send->setEnabled(false);
}

void MainWindow::showStdOut(QString msg)
{
	QString message = "[" + QTime::currentTime().toString("hh:mm:ss.zzz") + "]" + msg;
	this->output->append(message);
}
