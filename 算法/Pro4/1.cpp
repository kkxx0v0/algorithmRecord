//#include <iostream>
//#include <vector>
//using namespace std;
//int line[10];// 炸弹位置
//int zombie[10];// 僵尸位置
//vector<int> f;// 一行中炸弹的排列组合
//int ans = 1 << 30;
//bool bit(int x, int p) 
//{
//	return x & (1 << p);
//}
//bool check(int x) 
//{
//	int boom = line[x] | 
//		line[x] << 1 | 
//		line[x] >> 1 | 
//		line[x + 1] | 
//		line[x + 1] << 1 | 
//		line[x + 1] >> 1 |
//		line[x - 1] | 
//		line[x - 1] << 1 | 
//		line[x - 1] >> 1;
//	return (boom & zombie[x]) == zombie[x];
//}
//void dfs(int k)
//{
//	if (k == 6) 
//	{
//		int sum = 0;
//		for (int i = 1; i <= 6; i++)
//		{
//			if (!check(i))
//				return;
//		}
//		for (int i = 2; i <= 5; i++)
//		{ 
//			for (int j = 0; j < 9; j++)
//			{ 
//				if (bit(line[i], j))
//					sum += (i == 3 || i == 4) ? 175 : 150;
//			}
//		}
//		ans = min(sum, ans);
//		return;
//	}
//	for (int i : f) 
//	{
//		if (i & (line[k - 1] | line[k - 1] << 1 | line[k - 1] >> 1))
//			continue;
//		line[k] = i;
//		dfs(k + 1);
//	}
//}
//int main() 
//{
//	int map[7][10];// 用于表示僵尸分布情况的数组
//	for (int i = 1; i <= 6; i++)
//	{ 
//		for (int j = 0; j < 9; j++)
//		{
//			cin >> map[i][j];
//			zombie[i] |= map[i][j] << j;
//		}
//	}
//	for (int i = 0; i < 1 << 8; i++) 
//	{
//		bool flag = true;
//		for (int j = 0; j < 7; j++)
//		{
//			if (bit(i, j) && bit(i, j + 1)) 
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag) 
//			f.push_back(i << 1);
//	}
//	dfs(2);
//	cout << ans << endl;
//}