#include<iostream>
using namespace  std;
int main()
{
	int n, m;
	int arr[11][11] = { 0 };
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		int k;
		cin >> k;
		while (k--)
		{
			char t;
			int a, b;
			cin >> t >> a >> b;
			if(t=='r')
				for (int i = 0; i < n; i++)
				{
					int temp = arr[a - 1][i];
					arr[a - 1][i] = arr[b - 1][i];
					arr[b - 1][i] = temp;
				}
			else if(t=='c')
				for (int i = 0; i < m; i++)
				{
					int temp = arr[i][a - 1];
					arr[i][a - 1] = arr[i][b - 1];
					arr[i][b - 1] = temp;
				}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << arr[i][j];
			cout << endl;
		}
	}
}