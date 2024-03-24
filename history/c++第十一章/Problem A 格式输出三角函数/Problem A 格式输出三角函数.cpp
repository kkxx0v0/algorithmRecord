#include<iostream>
#include<iomanip>
#include<math.h>
#include"test.cpp"
using namespace std;
const double p_i = 3.14159265;
void test()
{
	int n;
	cin >> n;
	{
		for (int i = 1; i <= n; i++)
		{
			double temp = i * 2 * p_i / 360;
			cout << std::left << setw(3)
				<< i
				<< std::left << fixed << setprecision(5) << setw(10)
				<< sin(temp)
				<< std::left << fixed << setprecision(5) << setw(10)
				<< cos(temp)
				<< std::left << fixed << setprecision(5)
				<< tan(temp)
				<< endl;
		}
	}
}
int main()
{
	test();
	int n;
	cin >> n;
	cout.setf(ios::left);
	for (int i = 1; i <= n; i++)
	{
		double num = i * p_i / 180.0;
		cout << setw(3);
		cout << i;
		cout << setprecision(5);
		cout << setiosflags(ios::fixed);
		cout << setw(10) << sin(num);
		cout << setw(10) << cos(num);
		cout << setw(10) << tan(num) << endl;
	}
}