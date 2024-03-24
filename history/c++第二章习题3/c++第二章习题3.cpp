#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 1;
		for (int i = 2; i<n; i++)
		{
			if (n % i == 0)
			{
				sum += i;
			}
		}
		if (n == sum)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}