#include "networkcommunication.h"

void NetworkCommunication::handleQuestionList(QJsonObject &obj)
{
	if(obj.take("cmdId").toInt(0) != 1){
		return;
	}
	QList<QuestionBrief> qbl;
	for(int i = 0; i < obj.length(); i++){
		QJsonObject jop = obj.value(QString::number(i)).toObject();
		QuestionBrief qbp;
		qbp.questionId = jop.value("questionId").toInt(0);
		qbp.title = jop.value("title").toString();
		qbp.passNum = jop.value("passNum").toInt(-1);
		qbp.submitNum = jop.value("submitNum").toInt(-1);
		if(qbp.questionId == 0){
			qWarning() << "Attach question ID invaild: questionId:" << qbp.questionId;
			emit this->stdOut(tr("收到信息中问题ID有一项值不合法, 抛弃."));
			continue;
		}
		if(qbp.title.isEmpty()){
			qWarning() << "Attach question title invaild: title is empty.";
			emit this->stdOut(tr("收到信息中题目标题为空, 抛弃."));
			continue;
		}
		if(qbp.passNum == -1){
			qWarning() << "Attach passNum invaild.";
			emit this->stdOut(tr("收到题目信息中通过数有问题, 置位未知."));
		}
		if(qbp.submitNum == -1){
			qWarning() << "Attach submitNum invaild.";
			emit this->stdOut(tr("收到题目信息中提交数有问题, 置位未知."));
		}
		qbl.append(qbp);
	}
	emit this->responseQuestionList(qbl);
}

void NetworkCommunication::handleQuestionContent(QJsonObject &obj)
{
	if(obj.take("cmdId").toInt(0) != 2){
		return;
	}
	Question q;
	q.questionId = obj.value("questionId").toInt(0);
	q.title = obj.value("title").toString();
	q.description = obj.value("description").toString();
	q.input = obj.value("input").toString();
	q.output = obj.value("output").toString();
	q.inputSample = obj.value("inputSample").toString();
	q.outputSample = obj.value("outputSample").toString();
	q.hint = obj.value("hint").toString();
	q.source = obj.value("source").toString();
	q.timeLimit = obj.value("timeLimit").toInt(-1);
	q.memoryLimit = obj.value("memoryLimit").toInt(-1);
	q.passNum = obj.value("passNum").toInt(-1);
	q.submitNum = obj.value("submitNum").toInt(-1);
	if(q.questionId == 0){
		qWarning() << "Attach question ID invaild: questionId:" << q.questionId;
		emit this->stdOut(tr("收到信息中问题目ID值不合法, 抛弃."));
		return;
	}
	if(q.title.isEmpty()){
		qWarning() << "Attach question title invaild: title is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到信息中题目标题为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.description.isEmpty()){
		qWarning() << "Attach question description invaild: description is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到信息中题目描述为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.input.isEmpty()){
		qWarning() << "Attach question input invaild: input is empty? empty maybe receive '(empty)'? questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中输入为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.output.isEmpty()){
		qWarning() << "Attach question output invaild: output is empty. impossible. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中输出为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.inputSample.isEmpty()){
		qWarning() << "Attach question inputSample invaild: inputSample is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中样例输入为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.outputSample.isEmpty()){
		qWarning() << "Attach question outputSample invaild: outputSample is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中样例输出为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.hint.isEmpty()){
		qWarning() << "Attach question hint invaild: hint is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中样例输出为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.source.isEmpty()){
		qWarning() << "Attach question source invaild: source is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中来源为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.timeLimit == -1){
		qWarning() << "Attach question source invaild: timeLimit is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中时间限制为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.memoryLimit == -1){
		qWarning() << "Attach question source invaild: memoryLimit is empty. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中内存限制为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.passNum == -1){
		qWarning() << "Attach question passNum invaild. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中通过数为空. 题目ID: %1").arg(q.questionId));
	}
	if(q.submitNum == -1){
		qWarning() << "Attach question submitNum invaild. questionId:" << q.questionId;
		emit this->stdOut(tr("收到题目信息中提交数为空. 题目ID: %1").arg(q.questionId));
	}
	emit this->responseQuestionContent(q);
}

void NetworkCommunication::handleJudge(QJsonObject &obj)
{
	if(obj.take("cmdId").toInt(0) != 3){
		return;
	}
	JudgeResult jr;
	jr.username = obj.value("username").toString();
	jr.judgeId = obj.value("judgeId").toInt(0);
	jr.questionId = obj.value("questionId").toInt(0);
	jr.status = (Status)obj.value("status").toInt(0);
	jr.judgeTime = obj.value("judgeTime").toInt(0);
	jr.language = (Language)obj.value("language").toInt(0);
	jr.timeUsed = obj.value("timeUsed").toInt(0);
	jr.memoryUsed = obj.value("memoryUsed").toInt(0);
	jr.message = obj.value("message").toString();
	if(jr.username.isEmpty()){
		qWarning() << "Attach judge Username invaild.";
		emit this->stdOut(tr("收到判定信息中用户名为空."));
	}
	if(jr.judgeId == 0){
		qWarning() << "Attach judge judgeId invaild.";
		emit this->stdOut(tr("收到判定信息中judgeID为空"));
	}
	if(jr.questionId == 0){
		qWarning() << "Attach judge questionId invaild.";
		emit this->stdOut(tr("收到判定信息中题目ID值为空"));
	}
	if(jr.status == 0){
		qWarning() << "Attach judge status invaild.";
		emit this->stdOut(tr("收到判定信息中题目判定状态为空"));
	}
	if(jr.judgeTime == 0){
		qWarning() << "Attach judge judgeTime invaild. Maybe really in 1970s?";
		emit this->stdOut(tr("收到判定信息中题目判定时间戳状态为空"));
	}
	if(jr.language == 0){
		qWarning() << "Attach judge languageId invaild.";
		emit this->stdOut(tr("收到判定信息中题目语言ID状态为空"));
	}
	if(jr.timeUsed == 0){
		qWarning() << "Attach judge timeUsed invaild.";
		emit this->stdOut(tr("收到判定信息中题目语言ID状态为空"));
	}
	if(jr.memoryUsed == 0){
		qWarning() << "Attach judge memoryUsed invaild.";
		emit this->stdOut(tr("收到判定信息中题目语言ID状态为空"));
	}
	if(jr.message.isEmpty()){
		if(jr.status == 9){
			qWarning() << "Attach judge mo message while is compile error.";
			emit this->stdOut(tr("收到判定信息中没有其他信息."));
		}
	}
	emit this->responseJudge(jr);
}

void NetworkCommunication::handleUserInfomation(QJsonObject &obj)
{
	if(obj.value("cmdId").toInt(0) != 4){
		return;
	}
	User user;
	user.userId = obj.value("userId").toInt(0);
	user.username = obj.value("username").toString();
	user.userGroup = (UserGroup)obj.value("userGroup").toInt(0);
	user.email = obj.value("email").toString();
	user.token = obj.value("token").toString();

	emit this->responseUserInformation(user);
}

void NetworkCommunication::handleMessage(QJsonObject &obj)
{
	if(obj.value("cmdId").toInt(0) != -1){
		return;
	}
	QString msg = obj.value("message").toString(QString());
	if(msg.isEmpty()){
		qWarning() << "Receive cmdId = -1 but message is empty, abandoned.";
		emit this->stdOut(tr("收到信息但信息为空, 放弃"));
		return;
	}
	emit this->stdOut(msg);
}

NetworkCommunication::NetworkCommunication(Network *network, QObject *parent) : QObject(parent)
{
	this->network = network;
	connect(network, SIGNAL(msgReceived(QJsonDocument)), this, SLOT(msgReceive(QJsonDocument)));
}

void NetworkCommunication::requestQuestionList()
{
	QJsonObject obj;
	obj["cmdId"] = GetQuestionList;

	QJsonDocument doc(obj);
	this->network->msgSend(doc);
}

void NetworkCommunication::requestQuestionContent(int questionId)
{
	QJsonObject obj;
	obj["cmdId"] = GetQuestionContent;
	obj["questionId"] = questionId;

	QJsonDocument doc(obj);
	this->network->msgSend(doc);
}

void NetworkCommunication::requestJudge(Judge judge)
{
	QJsonObject obj;
	obj["cmdId"] = GetJudged;
	obj["username"] = judge.username;
	obj["token"] = judge.token;
	obj["programSource"] = judge.programSource;
	obj["language"] = (int)judge.language;
	obj["questionId"] = judge.questionId;
	obj["judgeId"] = judge.judgeId;

	QJsonDocument doc(obj);
	this->network->msgSend(doc);
}

void NetworkCommunication::requestUserInformation(QString user, QString token)
{
	QJsonObject obj;
	obj["cmdId"] = GetUserInformation;
	obj["username"] = user;
	obj["token"] = token;

	QJsonDocument doc(obj);
	this->network->msgSend(doc);
}

void NetworkCommunication::msgReceive(QJsonDocument doc)
{
	if(!doc.isObject()){
		qWarning() << "Received JSON is not an object! Maybe an array? doc:" << doc;
		return;
	}
	QJsonObject obj = doc.object();
	switch(obj.value("cmdId").toInt(0)){
		case Message: this->handleMessage(obj); break;
		case GetQuestionList: this->handleQuestionList(obj); break;
		case GetQuestionContent: this->handleQuestionContent(obj); break;
		case GetJudged: this->handleJudge(obj); break;
		case GetUserInformation: this->handleUserInfomation(obj); break;
		default: qDebug() << "Invaild message received, cmdId not found or out of range? doc:" << doc;
			return;
	}
}
