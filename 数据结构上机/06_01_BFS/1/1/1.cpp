#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int main()
{
	int m = 0;
	cin >> m;
	while (m--)
	{
		int n, e, s;
		cin >> n >> e >> s;
		int map[10][10];
		int *p = new int[n];
		queue<int> q;
		
		//初始化
		memset(map, 0, sizeof(map));
		memset(p, 0, n*sizeof(int));

		//对矩阵图连接边赋值为1
		int from, to;
		for (int i = 0; i < e; i++)
		{
			cin >> from >> to;
			map[from][to] = map[to][from] = 1;
		}
		
		q.push(s);
		p[s] = 1;
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
			{
				if (map[temp][i] == 1)
				{
					if (p[i]==0)
					{
						p[i] = 1;
						q.push(i);
					}
				}
			}
			cout << temp << " ";
		}
		cout << endl;
	}
	return 0;
}