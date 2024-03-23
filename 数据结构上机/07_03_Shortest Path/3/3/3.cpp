#include<iostream>
#include<string.h>
using namespace std;
unsigned int map[3000][3000];
unsigned int way[3000];
unsigned int is[3000];
int main()
{
	int n,c,s,t;//N cities	C highways from S to T
	memset(map, 0, sizeof(map));
	memset(way, -1, sizeof(way));
	memset(is, 0, sizeof(is));
	cin >> n >> c >> s >> t;
	int x, y, w;
	for (int i = 0; i < c; i++)
	{
		cin >> x >> y >> w;
		if (map[x][y]==0 || map[x][y] > w)
		{
			map[x][y] = map[y][x] = w;
		}
	}

	way[s] = 0;
	while (true)
	{
		int min = 1;
		for (int i = 2; i <= n; i++)
		{
			if (way[i]<way[min])
			{
				if (is[i]==0)
				{
					min = i;
				}
			}
		}
		if (min == t)
		{
			cout << way[t] << endl;
			return 0;
		}
		is[min] = 1;
		for (int i = 1; i <= n; i++)
		{
			unsigned int tempval = map[min][i];
			if (tempval)
			{
				tempval += way[min];
				if (way[i] == -1)
				{
					way[i] = tempval;
				}
				else if (way[i] > tempval)
				{
					way[i] = tempval;
				}
			}
		}
		way[min] = -1;
	}
}