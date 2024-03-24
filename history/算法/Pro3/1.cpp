//#include<iostream>
//using namespace std;
//int a[5000]{}, b[5000]{};
//int map[5000][5000];
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		cin >> b[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (a[i] == b[j])
//			{
//				map[i][j] = map[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				int tmp1 = map[i - 1][j];
//				int tmp2 = map[i][j - 1];
//				map[i][j] = tmp1 > tmp2 ? tmp1 : tmp2;
//			}
//		}
//	}
//	cout << map[n][m] << endl;
//}