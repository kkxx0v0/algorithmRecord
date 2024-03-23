#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int seven = 0, w = 1;
		while (n)
		{
			int temp = n % 7;
			n /= 7;
			seven += (temp * w);
			w *= 10;
		}
		cout << seven << endl;
	}
}