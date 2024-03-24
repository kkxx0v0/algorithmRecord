#include<iostream>
#include<algorithm>
using namespace std;

struct Edge
{
	int u, v;
	int w;
	Edge(int _u, int _v, int _w) { u = _u; v = _v; w = _w; }
};
Edge* e[510000];
int father[210000];
//int Find(int x) 
//{
//	if (father[x] != x)
//		return Find(father[x]);
//	return x;
//}
int find(int x)
{
	if (father[x] != x)
		father[x] = find(father[x]);
	return father[x];
}
//bool Union(int x, int y)
//{
//	x = Find(x);
//	y = Find(y);
//	if (x != y)
//	{
//		father[x] = father[y] = x > y ? y : x;
//		return true;
//	}	
//	return false;
//}
bool cmp(const Edge* x, const Edge* y)
{
	return x->w < y->w;
}

bool cmp(const Edge& x, const Edge& y)
{
	return x.w < y.w;
}

int n, m;
bool judge()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (Find(i) == i)
			cnt++;
	return cnt == 1;
}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		father[i] = i;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		e[i] = new Edge(u, v, w);
//	}
//	sort(e,e+m,cmp);
//	long long sum = 0;
//	/*int i = 0;
//	while (judge() != true && i < m)
//	{
//		int u = e[i]->u, v = e[i]->v;
//		if (Union(u, v))
//		{
//			sum += e[i]->w;
//		}
//		++i;
//	}*/
//	int cnt = 0;
//	for (int i = 0; i < m; ++i)
//	{
//		int a = e[i]->u, b = e[i]->v, w = e[i]->w;
//		int pa = Find(a), pb = Find(b);
//		if (pa != pb)
//		{
//			father[pa] = pb;
//			sum += w;
//			++cnt;
//		} 
//		if (cnt == n - 1) break;
//	}
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//		p[i] = i;
//	for (int i = 1; i <= m; ++i)
//	{
//		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//	}
//	sort(edges + 1, edges + 1 + m, cmp);
//	long long int sum = 0;
//	int cnt = 0;
//	for (int i = 1; i <= m; ++i)
//	{
//		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
//		int pu = find(u), pv = find(v);
//		if (pu != pv)
//		{
//			p[pu] = pv;
//			sum += w;
//			++cnt;
//		} 
//		if (cnt == n - 1) 
//			break;
//	}
//	cout << sum << endl;
//	return 0;
//}