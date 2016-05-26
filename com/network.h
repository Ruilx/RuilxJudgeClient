#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>

class Network : public QObject
{
	Q_OBJECT
	QTcpSocket *socket;
	QString host;
	int port;
public:
	explicit Network(QString host, int port, QObject *parent = 0);
	~Network();
	bool isRunning();
	bool doConnect();
	bool doDisconnect();
signals:
	void connected();
	void disconnected();
	void msgReceived(QJsonDocument doc);
	void stdOut(QString msg);
private slots:
	void clientStarted();
	void clientStopped();
public slots:
	void msgSend(QJsonDocument doc);
	void receive();
private:
	int timerId;
	qint64 bytesAvailable;
protected:
	void timerEvent(QTimerEvent *e);
};

#endif // NETWORK_H
