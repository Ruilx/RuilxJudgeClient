#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QtCore>

class Config : public QObject
{
	Q_OBJECT
	QSettings *ini;
public:
	explicit Config(QString filename, QObject *parent = 0);
	int getNetworkPort();
	QString getNetworkHostName();

signals:

public slots:
};

#endif // CONFIG_H
