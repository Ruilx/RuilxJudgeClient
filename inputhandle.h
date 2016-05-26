#ifndef INPUTHANDLE_H
#define INPUTHANDLE_H

#include <QObject>
#include <QtCore>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileDialog>
#include "com/global.h"

class InputHandle : public QObject
{
	Q_OBJECT
	void showHelp();
public:
	explicit InputHandle(QObject *parent = 0);
	void inputProcessor(QString cmdStr);
signals:
	void stdOut(QString msg);
	void sendQuestionList();
	void sendQuestionContent(int questionId);
	void sendJudge(Judge judge);
	void sendUserInformation(QString user, QString token);
public slots:
};

#endif // INPUTHANDLE_H
