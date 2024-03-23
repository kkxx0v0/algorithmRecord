#include<iostream> 
using namespace std;
int f(int n)//递归解法
{
	if (n == 0 || n == 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}
int main()
{
	int n;
	cin >> n;
	cout << f(n) << endl;

	//动态规划解法
	int a = 1, b = 1, c = 0;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		b = a;
		a = c;
	}
	if (n == 0 || n == 1)
		cout << 1;
	else
		cout << c;
	return 0;
}