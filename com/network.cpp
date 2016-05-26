#include "network.h"

Network::Network(QString host, int port, QObject *parent) : QObject(parent)
{
	this->socket = new QTcpSocket;
	this->host = host;
	this->port = port;
	connect(socket, SIGNAL(connected()), this, SLOT(clientStarted()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(clientStopped()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
	qDebug() << "Client started.";
	this->bytesAvailable = 0;
	timerId = this->startTimer(10);
}

Network::~Network()
{

}

bool Network::isRunning()
{
	return this->socket->isOpen();
}

bool Network::doConnect()
{
	this->socket->connectToHost(QHostAddress(this->host), this->port);
	if(!this->socket->waitForConnected()){
		qWarning() << "Server connected failed." << this->host << ":" << this->port;
		emit this->stdOut(tr("服务器连接失败: %1:%2").arg(this->host).arg(this->port));
		return false;
	}
	qInfo() << "Server connected." << this->host << ":" << this->port;
	emit this->stdOut(tr("服务器连接成功: %1:%2").arg(this->host).arg(this->port));
	emit this->connected();
	return true;
}

bool Network::doDisconnect()
{
	this->socket->disconnectFromHost();
//	if(!this->socket->waitForDisconnected()){
//		qWarning() << "Server disconnect failed." << this->host << ":" << this->port;
//		emit this->stdOut(tr("服务器断开失败: %1:%2").arg(this->host).arg(this->port));
//		return false;
//	}
	qInfo() << "Server disconnected." << this->host << ":" << this->port;
	emit this->stdOut(tr("服务器断开成功: %1:%2").arg(this->host).arg(this->port));
	emit this->disconnected();
	return true;
}

void Network::clientStarted()
{

}

void Network::clientStopped()
{
	this->stdOut(tr("服务器已断开连接"));
}

void Network::msgSend(QJsonDocument doc)
{
	qDebug() << "Sent:" << doc;
	socket->write(doc.toBinaryData());
}

void Network::receive()
{
	timerId = startTimer(10);
}

void Network::timerEvent(QTimerEvent *e)
{
	Q_UNUSED(e);
	qint64 bytes = bytesAvailable;
	bytesAvailable = socket->bytesAvailable();
	if(bytesAvailable != bytes){
		return;
	}
	killTimer(timerId);
	timerId = 0;
	if(bytesAvailable == 0){
		return;
	}
	bytesAvailable = 0;

	QByteArray data = socket->readAll();
	QJsonDocument doc = QJsonDocument::fromBinaryData(data);
	if(doc.isNull()){
		qWarning() << "Invalid JSON received.";
		return;
	}
	qDebug() << "Receive JSON document:" << doc;
	emit this->msgReceived(doc);
}



