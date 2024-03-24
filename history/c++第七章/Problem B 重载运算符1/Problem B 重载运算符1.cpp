#include<iostream>
using namespace std;
class Integer
{
public:
	short num1, num2;
	char ch;
	short operator+()
	{
		return num1 + num2;
	}
	short operator-()
	{
		return num1 - num2;
	}
	short operator*()
	{
		return num1 * num2;
	}
	short operator/(Integer)
	{
		return num1 / num2;
	}
};
int main()
{
	Integer i;
	while (cin >> i.ch >> i.num1 >> i.num2)
	{
		switch (i.ch)
		{
		case '+':
			cout<<i.operator+()<<endl;
			break;
		case '-':
			cout<<i.operator-() << endl;
			break;
		case '*':
			cout<<i.operator*() << endl;
			break;
		case '/':
			cout<<i.operator/(i) << endl;
			break;
		default:
			break;
		}
	}
}