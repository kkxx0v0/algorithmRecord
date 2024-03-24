#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 2; n>1; i++)
		{
			if (n % i == 0)
			{
				cout << i << endl;
				n /= i;
				i--;
			}
		}
	}
}