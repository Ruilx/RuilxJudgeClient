#ifndef GLOBAL
#define GLOBAL

//控制端发送的请求类型码
enum CmdId{
	NoneCmdId = 0,
	GetQuestionList = 1,
	GetQuestionContent = 2,
	GetJudged = 3,
	GetUserInformation = 4,

	Message = -1,
};

//程序判定返回码
enum Status{
	NoneStatus = 0,
	Accepted = 1,
	PresentationError = 2,
	WrongAnswer = 3,
	OutputLimitExcedded = 4,
	ValidatorError = 5,
	MemoryLimitExcedded = 6,
	TimeLimitExcedded = 7,
	RuntimeError = 8,
	CompileError = 9,
	SystemError = 10,
	RestrictedFunction = 11,
	Running = 12,
	Hidden = 13,
};

//用户类型ID
enum UserGroup{
	UnknownGroup = 0,
	Judger = 1,
	Manager = 2,
	Admin = 3,
};

//程序源码语言ID
enum Language{
	None = 0,
	C = 1,
	Cpp = 2,
	Java = 3,
	Python = 4,
	Php = 5,
	Lua = 6,
};

//问题列表Node
typedef struct{
	int questionId;
	QString title;
	int passNum;
	int submitNum;
}QuestionBrief;

//问题
typedef struct{
	int questionId;
	QString title;
	QString description;
	QString input;
	QString output;
	QString inputSample;
	QString outputSample;
	QString hint;
	QString source;
	int timeLimit;
	int memoryLimit;
	int passNum;
	int submitNum;
}Question;

//判题
typedef struct{
	QString username;
	QString token;
	QString programSource;
	Language language;
	int questionId;
	int judgeId;
}Judge;

//判题结果
typedef struct{
	QString username;
	int judgeId;
	int questionId;
	Status status;
	int judgeTime;
	Language language;
	int timeUsed;
	int memoryUsed;
	QString message;
}JudgeResult;

//用户信息
typedef struct{
	int userId;
	QString username;
	UserGroup userGroup;
	QString email;
	QString token;
}User;

#endif // GLOBAL

