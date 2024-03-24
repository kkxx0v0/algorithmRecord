#include<iostream>
using namespace std;
int main()
{
	short n;
	while (cin >> n)
	{
		if (((n % 3) == 2) && ((n % 5) == 3) && ((n % 7) == 2))
			cout << 1 << endl; \
		else
			cout << 0 << endl;
	}
}