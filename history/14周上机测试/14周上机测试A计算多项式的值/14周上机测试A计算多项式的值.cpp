#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x, n;
	while (cin >> x >> n)
	{
		int sum = 0;
		int k = 1;
		for (int i = 0; i <= n; i++)
		{
			sum += pow(x, i);
			if (sum < 0)
			{
				cout << "Overflow" << endl;
				k = 0;
				break;
			}

		}
		if (k)
			cout << sum << endl;
	}
}