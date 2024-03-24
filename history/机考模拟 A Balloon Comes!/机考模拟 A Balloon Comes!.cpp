#include<iostream>
using namespace std;
int main()
{
	//输入包含多个测试用例
	//输入的第一行是一个整数T（0 <T <1000），它是测试用例的数量。
	//每个测试用例都包含一个char C（+， - ，*，/）和两个整数A和B（0 <A，B <10000）。
	//对于每种情况，请打印操作结果。当且仅当结果不是整数时应该四舍五入到小数点后2位。
	int t;
	cin >> t;
	while (t--)
	{
		char ch;
		cin >> ch;
		if (ch == '+')
			ch = 1;
		if (ch == '-')
			ch = 2;
		if (ch == '*')
			ch = 3;
		if (ch == '/')
			ch = 4;
		int a, b;
		cin >> a >> b;
		switch (ch)
		{
		case  1:
			cout << a + b << endl;
			break;
		case  2:
			cout << a - b << endl;
			break;
		case  3:
			cout << a * b << endl;
			break;
		case  4:
			if (a / b == (double)a / b)
				cout << a / b << endl;
			else
				printf("%.2f\n", (double)a / b);
			break;
		default:
			break;
		}
	}
}