#include<iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		while (num >= 10)
		{
			int temp = 0;
			while (num)
			{
				temp += (num % 10);
				num /= 10;
			}
			num = temp;
		}
		cout << num << endl;
	}
}