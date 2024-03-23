#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a, b;
	while (cin>>a>>b)
	{
		int num1, num2;
		num1 = num2 = 0;
		for (int i = 0; a; i++)
		{
			num1 += ((a % 10) * pow(2, i));
			a /= 10;
		}
		for (int i = 0; b; i++)
		{
			num1 += ((b % 10) * pow(2, i));
			b /= 10;
		}
		int sum = num1 + num2;
		long long outp=0;
		for (int i = 0; sum; i++)
		{
			outp += (sum % 2) * pow(10, i);
			sum /= 2;
		}
		cout << outp << endl;
	}
}