#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	string name;
	const int salary = 2000;
	virtual void show() = 0;
};
class Teacher:public people
{
public:
	char level;
	int time;
	virtual void show() 
	{
		cout << name << " ";
		int money = 0;;
		switch (level)
		{
		case '1':
			money = 50;
			break;
		case '2':
			money = 30;
			break;
		case '3':
			money = 20;
			break;
		default:
			break;
		}
		cout << salary + money * time << endl;
	}
};
class Manager :public people
{
public:
	int jobwage;
	virtual void show()
	{
		cout << name << " ";
		cout << salary + jobwage << endl;
	}
};
class Worker :public people
{
public:
	int day;
	virtual void show()
	{
		cout << name << " ";
		cout << salary + 20*day << endl;
	}
};
int main()
{
	Teacher T;
	Manager M;
	Worker W;
	cin >> T.name >> T.level >> T.time >> M.name >> M.jobwage >> W.name >> W.day;
	T.show();
	M.show();
	W.show();
}