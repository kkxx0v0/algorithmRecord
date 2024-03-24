#include<iostream>
#include<string.h>
using namespace std;
int map[5000][5000];
int is[5000];
int n;
void find(int i)
{
	for (int j = 0; j < n; j++)
	{
		if (map[i][j] == 1)
		{
			if (is[j]==0)
			{
				is[j] = 1;
				find(j);
			}
		}
	}
}
int main()
{
	cin >> n;
	int num = 0;
	memset(map, 0, sizeof(map));
	memset(is, 0, sizeof(is));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (is[i] == 0)
		{
			is[i] = 1;
			find(i);
			num++;
		}
	}
	cout << num << endl;
}