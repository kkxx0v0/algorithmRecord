//题意：
//和迷宫的输入差不多，‘* ’是墙，‘@’是油田，
//以一个油田为中心，如果它的东南西北一个各个角落，一共八个方向也有油田的话，这些油田就算作一个油田。
//分析：
//查找到‘@’的位置，找到一个，油田加1，对找到的‘@’的四周进行DFS查找，刚开始我以为和迷宫的做法差不多，我把查找过的地方用一个数组标记一下，后来测试结果不对，
//才发现在某一次存在题意中的相邻油田时，在主函数中会加1，而实际上这块油田我已经计算进去了，这样就重复了。正确的做法应该是把计算进去的那块油田变为‘* ’，这样
//就不存在重复计算了！！！
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id)
{
	if (r<0 || r>m || c<0 || c>n)
		return;
	if (idx[r][c] > 0 || pic[r][c] != '@')
		return;
	idx[r][c] = id;
	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (dr != 0 || dc != 0)
				dfs(r + dr, c + dc, id);
		}
	}
}
int main()
{
	while (scanf("%d%d",&m,&n)==2&&m&&n)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%s", pic[i]);
		}
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for(int i=0;i<m;i++)
			for (int j = 0; j < n; j++)
			{
				if (idx[i][j]==0&&pic[i][j]=='@')
				{
					dfs(i, j, ++cnt);
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}