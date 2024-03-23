#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 2;; i++)
		{
			if (!(n % i))
			{
				cout << " " << i;
				n /= i;
				i -= 1;
			}
			if (n == 1)
				break;
		}
		cout << endl;
	}
}