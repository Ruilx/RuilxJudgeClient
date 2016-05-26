#include "config.h"

Config::Config(QString filename, QObject *parent) : QObject(parent)
{
	this->ini = new QSettings(filename, QSettings::IniFormat);
}

int Config::getNetworkPort()
{
	bool ok = false;
	int port = ini->value("network/port", 0).toInt(&ok);
	if((!ok) || port == 0){
		return 0;
	}
	return port;
}

QString Config::getNetworkHostName()
{
	return ini->value("network/host", QString()).toString();
}

