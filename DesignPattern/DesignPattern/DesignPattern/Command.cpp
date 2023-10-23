#include <iostream>
#include <string>

using namespace std;

// 커맨드 인터페이스
class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() const = 0;
};

// 커맨드 기능 구현 클래스
class SimpleCommand : public Command
{
private:
	string mPayLoad;

public:
	explicit SimpleCommand(string payLoad) : mPayLoad(payLoad) {}
	void Execute() const override
	{
		cout << "SimpleCommand : 입력된 string을 출력합니다 -> " << this->mPayLoad << "\n";
	}
};

// 실제 연산이나 작업을 수행하는 객체
class Receiver
{
public:
	void DoSomething(const string &a)
	{
		cout << "Receiver : " << a << " 작업중. \n";
	}

	void DoSomething2(const string &b)
	{
		cout << "Receiver : " << b << " 또한 작업중. \n";
	}
};

// 커맨드 기능 구현 클래스 2
class ComplexCommand : public Command
{
private:
	Receiver* mReceiver;

	string mA;
	string mB;

public:
	ComplexCommand(Receiver* receiver, string a, string b)
		: mReceiver(receiver), mA(a), mB(b)
	{
		
	}

	void Execute() const override
	{
		cout << "ComplexCommand : 복잡한 작업은 수신자를 통해 수행" << "\n";
		this->mReceiver->DoSomething(this->mA);
		this->mReceiver->DoSomething2(this->mB);
	}
};

// 객체를 보관하고 실행하는 역할
class InVoker
{
private:
	Command* onStart;
	Command* onFinish;

public:
	~InVoker()
	{
		delete onStart;
		delete onFinish;
	}

	void SetOnStart(Command* command)
	{
		this->onStart = command;
	}

	void SetOnFinish(Command* command)
	{
		this->onFinish = command;
	}

	void DoSomethingImportant()
	{
		cout << "Invoker : 명령 시작시 수행할 무언가" << "\n";
		if (this->onStart)
			this->onStart->Execute();

		cout << "Invoker : 무언가 수행" << "\n";
		cout << "Invoker : 끝나고 수행할 무언가 " << "\n";
		if (this->onFinish)
			this->onFinish->Execute();
	}
};

int main()
{
	InVoker* invoker = new InVoker;
	invoker->SetOnStart(new SimpleCommand("HI"));
	Receiver* receiver = new Receiver;
	invoker->SetOnFinish(new ComplexCommand(receiver, "호출 시작", "호출 끝"));
	invoker->DoSomethingImportant();

	delete invoker;
	delete receiver;

	return 0;
}