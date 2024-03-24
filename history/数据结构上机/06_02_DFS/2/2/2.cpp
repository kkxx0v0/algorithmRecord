#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int n, e, s;
int map[20][20]; 
int* p;

void DFS(int num)
{
	cout << num << " ";
	p[num] = 1;
	for (int i = 0; i < n; i++)
	{
		if (map[num][i] == 1)
		{
			if (p[i]==0)
			{
				DFS(i);
			}
		}
	}
}
int main()
{
	int m = 0;
	cin >> m;
	while (m--)
	{
		cin >> n >> e >> s;
		p = new int[n];
		queue<int> q;

		//初始化
		memset(map, 0, sizeof(map));
		memset(p, 0, n * sizeof(int));

		//对矩阵图连接边赋值为1
		int from, to;
		for (int i = 0; i < e; i++)
		{
			cin >> from >> to;
			map[from][to] = map[to][from] = 1;
		}

		DFS(s);
		cout << endl;
	}
	return 0;
}