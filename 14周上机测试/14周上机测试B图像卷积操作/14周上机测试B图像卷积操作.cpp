#include<iostream>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int** p = new int*[m+2];
		for (int i = 0; i < m + 2; i++)
		{
			p[i] = new int[n + 2];
			for (int j = 0; j < n + 2; j++)
				p[i][j] = 0;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> p[i][j];
		int** arr = new int* [m+2];
		for (int i = 0; i < m+2 ; i++)
		{
			arr[i] = new int[n+2];
			for (int j = 0; j < n + 2; j++)
				arr[i][j] = 0;
		}
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] =
					p[i - 1][j - 1] - p[i - 1][j] + p[i - 1][j + 1]
					+ p[i][j - 1] - p[i][j] - p[i][j + 1]
					+ p[i + 1][j - 1] - p[i + 1][j] - p[i + 1][j + 1];
			}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j-1)
					cout << " ";
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
}