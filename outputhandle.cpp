#include "outputhandle.h"

OutputHandle::OutputHandle(QObject *parent) : QObject(parent)
{
	statusMap.insert(NoneStatus, tr("None Status"));
	statusMap.insert(Accepted, tr("Accepted"));
	statusMap.insert(PresentationError, tr("Presentation Error"));
	statusMap.insert(WrongAnswer, tr("Wrong Answer"));
	statusMap.insert(OutputLimitExcedded, tr("Output Limit Excedded"));
	statusMap.insert(ValidatorError, tr("Validator Error"));
	statusMap.insert(MemoryLimitExcedded, tr("Memory Limit Excedded"));
	statusMap.insert(TimeLimitExcedded, tr("Time Limit Excedded"));
	statusMap.insert(RuntimeError, tr("Runtime Error"));
	statusMap.insert(CompileError, tr("Compile Error"));
	statusMap.insert(SystemError, tr("System Error"));
	statusMap.insert(RestrictedFunction, tr("Restricted Function"));
	statusMap.insert(Running, tr("Running"));
	statusMap.insert(Hidden, tr("Hidden"));

	userGroupMap.insert(UnknownGroup, tr("未知组"));
	userGroupMap.insert(UnknownGroup, tr("评测组"));
	userGroupMap.insert(UnknownGroup, tr("运维组"));
	userGroupMap.insert(UnknownGroup, tr("管理员"));

	languageMap.insert(None, "未知语言");
	languageMap.insert(C, "C");
	languageMap.insert(Cpp, "C++");
	languageMap.insert(Java, "Java");
	languageMap.insert(Python, "Python");
	languageMap.insert(Php, "PHP");
	languageMap.insert(Lua, "Lua");
}

void OutputHandle::receiveQuestionList(QList<QuestionBrief> questions)
{
	emit this->stdOut(tr("==========题目列表=========="));
	emit this->stdOut(tr("服务器共有 %1 个题目").arg(questions.length()));
	emit this->stdOut(tr("%1 %2 %3 %4 %5%").arg("问题ID", 6)
					  .arg("标题", -41)
					  .arg("题目通过数", 5)
					  .arg("题目尝试数", 5)
					  .arg("通过率", 5));
	foreach(auto p, questions){
//		emit this->stdOut(tr("问题ID: %1").arg(p.questionId));
//		emit this->stdOut(tr("标题: %1").arg(p.title));
//		emit this->stdOut(tr("题目通过数: %1").arg(p.passNum));
//		emit this->stdOut(tr("题目尝试数: %1").arg(p.submitNum));
//		emit this->stdOut(tr("通过率: %1%").arg((100 * (double)p.passNum / (double)p.submitNum)));
//		emit this->stdOut("");
		emit this->stdOut(tr("%1 %2 %3 %4 %5%").arg(p.questionId, 8).arg(p.title, -43).arg(p.passNum, 10).arg(p.submitNum, 10).arg((100 * (double)p.passNum / (double)p.submitNum), 8));
	}
	emit this->stdOut(tr("请通过question命令查看题目具体内容."));
}

void OutputHandle::receiveQuestionContent(Question question)
{
	emit this->stdOut(tr("==========题目信息=========="));
	emit this->stdOut(tr("问题ID: %1").arg(question.questionId));
	emit this->stdOut(tr("标题: %1").arg(question.title));
	emit this->stdOut(tr("描述: %1").arg(question.description));
	emit this->stdOut(tr("输入描述: %1").arg(question.input));
	emit this->stdOut(tr("输出描述: %1").arg(question.output));
	emit this->stdOut(tr("样例输入: %1").arg(question.inputSample));
	emit this->stdOut(tr("样例输出: %1").arg(question.outputSample));
	emit this->stdOut(tr("备注: %1").arg(question.hint));
	emit this->stdOut(tr("来源: %1").arg(question.source));
	emit this->stdOut(tr("时间限制: %1").arg(question.timeLimit));
	emit this->stdOut(tr("内存限制: %1").arg(question.memoryLimit));
	emit this->stdOut(tr("题目通过数: %1").arg(question.passNum));
	emit this->stdOut(tr("题目尝试数: %1").arg(question.submitNum));
	emit this->stdOut(tr("通过率: %1%").arg((100 * (double)question.passNum / (double)question.submitNum)));
	emit this->stdOut(tr("请通过judge命令提交题目源码."));
}

void OutputHandle::receiveJudge(JudgeResult judge)
{
	emit this->stdOut(tr("==========判题结果=========="));
	emit this->stdOut(tr("用户名: %1").arg(judge.username));
	emit this->stdOut(tr("判题序列号: %1").arg(judge.judgeId));
	emit this->stdOut(tr("问题ID: %1").arg(judge.questionId));
	emit this->stdOut(tr("判定结果: %1").arg(statusMap.value(judge.status, tr("未知"))));
	emit this->stdOut(tr("判定时间: %1").arg(QDateTime::fromTime_t(judge.judgeTime).toString(Qt::SystemLocaleLongDate)));
	emit this->stdOut(tr("语言: %1").arg(languageMap.value(judge.language, tr("未知"))));
	emit this->stdOut(tr("所用时间: %1").arg(judge.timeUsed));
	emit this->stdOut(tr("所用内存: %1").arg(judge.memoryUsed));
	emit this->stdOut(tr("其他信息: %1").arg(judge.message));
}

void OutputHandle::receiveUserInformation(User user)
{
	emit this->stdOut(tr("==========用户信息=========="));
	emit this->stdOut(tr("用户ID: %1").arg(user.userId));
	emit this->stdOut(tr("用户名: %1").arg(user.username));
	emit this->stdOut(tr("E-mail: %1").arg(user.email));
	emit this->stdOut(tr("用户组: %1").arg(userGroupMap.value(user.userGroup, tr("未知"))));
	emit this->stdOut(tr("Token: %1").arg(user.token));
}

