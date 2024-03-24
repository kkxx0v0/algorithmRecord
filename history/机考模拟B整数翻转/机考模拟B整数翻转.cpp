#include<iostream>
using namespace std;
int main()
{
	long long n;
	while (cin >> n)
	{
		long long sum = 0;
		while (n)
		{
			sum *= 10;
			sum += (n % 10);
			n /= 10;
		}
		if (sum <= 2147483647 && sum >= -2147483648)
			cout << sum << endl;
		else
			cout << 0 << endl;
	}
}