#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int m = n / 1000;
		for (int i = 0; i < m; i++)
		{
			cout << "M";
		}
		n %= 1000;
		int b = n / 100;
		if (b == 9)
			cout << "CM";
		else if (b == 4)
			cout << "CD";
		else
		{
			if (b >= 5)
			{
				b -= 5;
				cout << "D";
			}
			for (int i = 0; i < b; i++)
				cout << "C";
		}
		n %= 100;
		int s = n / 10;
		if (s == 9)
			cout << "XC";
		else if (s == 4)
			cout << "XL";
		else 
		{
			if (s >= 5)
			{
				s -= 5;
				cout << "L";
			}
			for (int i = 0; i < s; i++)
				cout << "X";
		}
		n %= 10;
		int g = n;
		if (g == 9)
			cout << "IX";
		else if (g == 4)
			cout << "IV";
		else
		{
			if (g >= 5)
			{
				g -= 5;
				cout << "V";
			}
			for (int i = 0; i < g; i++)
				cout << "I";
		}
		cout << endl;
	}
}