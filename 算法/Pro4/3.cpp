#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[1000010];
int in[1000010], out[1000010];
int cnt[1000010];
int main() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		in[v]++;
		out[u]++;
		edge[u].push_back(v);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i] && out[i]) 
			q.push(i), cnt[i] = 1;
	while (q.size()) 
	{
		int k = q.front(); q.pop();
		for (int i : edge[k]) 
		{
			in[i]--;
			cnt[i] += cnt[k];
			if (!in[i] && out[i])
				q.push(i);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (out[i] == 0)
			ans += cnt[i];
	printf("%lld", ans);
}