#include<iostream>
using namespace std;
int main()
{
	//读入正方形的边长
	//打印由星号和空格组成的空心正方形
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || i == n-1)
					cout << "*";
				else if (j == 0 || j == n-1)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
