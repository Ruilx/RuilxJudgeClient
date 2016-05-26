#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H

#include <QObject>
#include <QtCore>
#include "global.h"
#include "network.h"

class NetworkCommunication : public QObject
{
	Q_OBJECT
	Network *network;
	//用来处理接收后的信息是题目列表的信息
	void handleQuestionList(QJsonObject &obj);
	//用来处理接收后的信息是题目内容的信息
	void handleQuestionContent(QJsonObject &obj);
	//用来处理接收后的信息是判定结果的信息
	void handleJudge(QJsonObject &obj);
	//用来处理接收后是用户信息的信息
	void handleUserInfomation(QJsonObject &obj);

	//用来处理接收后是信息Message的时候的信息
	void handleMessage(QJsonObject &obj);
public:
	//构造函数: 网络数据处理
	explicit NetworkCommunication(Network *network, QObject *parent = 0);

signals:
	//信号: 请求输出到屏幕
	void stdOut(QString msg);
	//信号: 返回了题目列表
	void responseQuestionList(QList<QuestionBrief> questionList);
	//信号: 返回了questionId的具体内容
	void responseQuestionContent(Question question);
	//信号: 返回了判题结果
	void responseJudge(JudgeResult result);
	//信号: 返回了tid用户信息
	void responseUserInformation(User user);
public slots:
	//槽: 请求题目列表
	void requestQuestionList();
	//槽: 请求题目内容
	void requestQuestionContent(int questionId);
	//槽: 请求判定题目
	void requestJudge(Judge judge);
	//槽: 请求用户信息
	void requestUserInformation(QString user, QString token);
private slots:
	//私有槽: 收到网络信息
	void msgReceive(QJsonDocument doc);
};

#endif // NETWORKCOMMUNICATION_H
