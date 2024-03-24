#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a > b)
		{
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		if (a > c)
		{
			a = a ^ c;
			c = a ^ c;
			a = a ^ c;
		}
		if (b > c)
		{
			b = c ^ b;
			c = c ^ b;
			b = c ^ b;
		}
		cout << a << " " << b << " " << c << endl;
	}
}