#include<iostream>
using namespace std;
int main()
{
	//要求输入一个5位正整数
	//然后分解出它的每位数字，并将这些数字按间隔2个空格的逆序形式打印输出。
	int n;
	cin >> n;
	for (; n; n /= 10)
	{
		cout << "  " << n % 10;//第一个数字前方也有2个空格
	}
	return 0;
}