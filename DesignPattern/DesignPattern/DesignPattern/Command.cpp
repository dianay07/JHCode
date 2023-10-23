#include <iostream>
#include <string>

using namespace std;

// Ŀ�ǵ� �������̽�
class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() const = 0;
};

// Ŀ�ǵ� ��� ���� Ŭ����
class SimpleCommand : public Command
{
private:
	string mPayLoad;

public:
	explicit SimpleCommand(string payLoad) : mPayLoad(payLoad) {}
	void Execute() const override
	{
		cout << "SimpleCommand : �Էµ� string�� ����մϴ� -> " << this->mPayLoad << "\n";
	}
};

// ���� �����̳� �۾��� �����ϴ� ��ü
class Receiver
{
public:
	void DoSomething(const string &a)
	{
		cout << "Receiver : " << a << " �۾���. \n";
	}

	void DoSomething2(const string &b)
	{
		cout << "Receiver : " << b << " ���� �۾���. \n";
	}
};

// Ŀ�ǵ� ��� ���� Ŭ���� 2
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
		cout << "ComplexCommand : ������ �۾��� �����ڸ� ���� ����" << "\n";
		this->mReceiver->DoSomething(this->mA);
		this->mReceiver->DoSomething2(this->mB);
	}
};

// ��ü�� �����ϰ� �����ϴ� ����
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
		cout << "Invoker : ��� ���۽� ������ ����" << "\n";
		if (this->onStart)
			this->onStart->Execute();

		cout << "Invoker : ���� ����" << "\n";
		cout << "Invoker : ������ ������ ���� " << "\n";
		if (this->onFinish)
			this->onFinish->Execute();
	}
};

int main()
{
	InVoker* invoker = new InVoker;
	invoker->SetOnStart(new SimpleCommand("HI"));
	Receiver* receiver = new Receiver;
	invoker->SetOnFinish(new ComplexCommand(receiver, "ȣ�� ����", "ȣ�� ��"));
	invoker->DoSomethingImportant();

	delete invoker;
	delete receiver;

	return 0;
}