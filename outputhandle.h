#ifndef OUTPUTHANDLE_H
#define OUTPUTHANDLE_H

#include <QObject>
#include <QtCore>
#include <QString>
#include <QStringList>
#include "com/global.h"

class OutputHandle : public QObject
{
	Q_OBJECT
	QMap<Status, QString> statusMap;
	QMap<UserGroup, QString> userGroupMap;
	QMap<Language, QString> languageMap;
public:
	explicit OutputHandle(QObject *parent = 0);

signals:
	void stdOut(QString msg);
public slots:
	void receiveQuestionList(QList<QuestionBrief> questions);
	void receiveQuestionContent(Question question);
	void receiveJudge(JudgeResult judge);
	void receiveUserInformation(User user);
};

#endif // OUTPUTHANDLE_H
