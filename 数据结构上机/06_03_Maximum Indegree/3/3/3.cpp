#include<iostream>
#include<string.h>
using namespace std;
int map[2505][2505];
int main()
{
	int m = 0;
	cin >> m;
	while (m--)
	{
		int n, c;
		cin >> n >> c;
		memset(map, 0, sizeof(map));
		int from, to;
		for (int i = 0; i < c; i++)
		{
			cin >> from >> to;
			map[to][from] = 1;
		}
		int max = 0;
		for (int i = 1; i <= n; i++)
		{
			int temp = 0;
			for (int j = 1; j <= n; j++)
			{
				temp += map[i][j];
			}
			if (temp>max)
			{
				max = temp;
			}
		}
		cout << max << endl;
	}
	return 0;
}