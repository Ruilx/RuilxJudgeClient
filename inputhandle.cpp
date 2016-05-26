#include "inputhandle.h"

void InputHandle::showHelp()
{
	emit this->stdOut(tr("==========命令帮助=========="));
	emit this->stdOut(tr("list                                              显示服务器所有题目"));
	emit this->stdOut(tr("question <question id>                            显示题目内容"));
	emit this->stdOut(tr("judge <question id> <language> <username> <token> 判定题目, language: C, C++, Java"));
	emit this->stdOut(tr("user <username> <token>                           获取用户信息"));
	emit this->stdOut(tr("help                                              获取帮助信息"));
	emit this->stdOut("");
	emit this->stdOut("Made by Ruilx<ruilxalxa@hotmail.com> @ GT-Soft Studio 2016");
	emit this->stdOut("Based on Qt5.6.0 GCC-64bit");
	emit this->stdOut("For report bugs: please visit www.ruilx.top");
	emit this->stdOut("RuilxJudgeClient v0.2.0-build 0660 GT-Soft Studio");
}

InputHandle::InputHandle(QObject *parent) : QObject(parent)
{

}

void InputHandle::inputProcessor(QString cmdStr)
{
	QStringList cmdList = cmdStr.split(QRegExp("\\s"), QString::SkipEmptyParts);
	if(cmdList.length() < 1){
		return;
	}
	qInfo() << "User issued command:" << cmdStr;
	emit this->stdOut(tr("输入的信息: %1").arg(cmdStr));
	QString cmd = cmdList.at(0);
	if(cmd == "list"){
		emit this->stdOut(tr("发送请求问题列表的命令."));
		emit this->sendQuestionList();
		return;
	}else if(cmd == "help"){
		this->showHelp();
		return;
	}else if(cmd == "question"){
		if(cmdList.length() < 2){
			qWarning() << "User input wrong command:" << cmdStr;
			emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
			return;
		}else{
			bool ok = false;
			int questionId = cmdList.at(1).toInt(&ok);
			if(!ok){
				qWarning() << "User input wrong command:" << cmdStr;
				emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
				return;
			}
			if(questionId == 0){
				qWarning() << "User input wrong command:" << cmdStr;
				emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
				return;
			}
			emit this->stdOut(tr("发送请求问题内容的命令."));
			emit this->sendQuestionContent(questionId);
			return;
		}
	}else if(cmd == "judge"){
		Judge judge;
		if(cmdList.length() < 5){
			qWarning() << "User input wrong command:" << cmdStr;
			emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
			return;
		}else{
			bool ok = false;
			int questionId = cmdList.at(1).toInt(&ok);
			if(!ok){
				qWarning() << "User input wrong command:" << cmdStr;
				emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
				return;
			}
			if(questionId == 0){
				qWarning() << "User input wrong command:" << cmdStr;
				emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
				return;
			}
			judge.questionId = questionId;
			QString username = cmdList.at(3);
			judge.username = username;
			QString token = cmdList.at(4);
			judge.token = token;
			QString language = cmdList.at(2);
			QString source;
			if(!QString::compare(language, "C", Qt::CaseInsensitive)){
				judge.language = C;
				source = QFileDialog::getOpenFileName(0, tr("打开一个C语言程序源码"), QDir::currentPath(), tr("C语言源程序(*.c)"));
			}else if(!QString::compare(language, "C++", Qt::CaseInsensitive)){
				judge.language = Cpp;
				source = QFileDialog::getOpenFileName(0, tr("打开一个C++语言程序源码"), QDir::currentPath(), tr("C++语言源程序(*.cpp)"));
			}else if(!QString::compare(language, "Java", Qt::CaseInsensitive)){
				judge.language = Java;
				source = QFileDialog::getOpenFileName(0, tr("打开一个Java语言程序源码"), QDir::currentPath(), tr("Java语言源程序(*.java)"));
			}else{
				qWarning() << "User input wrong command:" << cmdStr;
				emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
				return;
			}
			if(source.isEmpty()){
				return;
			}
			QFile sourceFile(source);
			if(!sourceFile.open(QIODevice::ReadOnly)){
				qWarning() << "File cannot open. File:" << source << "Message:" << sourceFile.errorString();
				emit this->stdOut(tr("文件'%1'无法打开, 信息:%2").arg(source).arg(sourceFile.errorString()));
				return;
			}
			judge.programSource = QString(sourceFile.readAll());
			judge.judgeId = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch() & 0x7FFFFFFF;

			emit this->stdOut(tr("发送请求题目判定的命令."));
			emit this->sendJudge(judge);
			return;
		}
	}else if(cmd == "user"){
		if(cmdList.length() < 3){
			qWarning() << "User input wrong command:" << cmdStr;
			emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
			return;
		}else{
			QString username = cmdList.at(1);
			QString token = cmd.at(2);

			emit this->stdOut(tr("发送请求用户信息的命令."));
			emit this->sendUserInformation(username, token);
			return;
		}
	}else{
		qWarning() << "User input wrong command:" << cmdStr;
		emit this->stdOut(tr("输入的信息有误, 请重新输入!"));
		return;
	}
}

