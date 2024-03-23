//#include<iostream>
//#include<vector>
//using namespace std;
//int x[8] = { -2,-1,1,2,2,1,-1,-2 };
//int y[8] = { 1,2,2,1,-1,-2,-2,-1 };
//int main()
//{
//	int x1, y1;
//	int x2, y2;
//	cin >> x1 >> y1;
//	cin >> x2 >> y2;
//	vector<vector<long long int>> dp(x1 + 1, vector<long long int>(y1 + 1, 0));
//	dp[x2][y2] = -1;
//	for (int i = 0; i < 8; ++i)
//	{
//		if (x2 + x[i] >= 0 &&
//			x2 + x[i] <= x1 &&
//			y2 + y[i] >= 0 &&
//			y2 + y[i] <= y1)
//		{
//			dp[x2 + x[i]][y2 + y[i]] = -1;
//		}
//	}
//	for (int i = 0; i <= x1; ++i)
//	{
//		if (dp[i][0] != -1)
//		{
//			dp[i][0] = 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (int i = 0; i <= y1; ++i)
//	{
//		if (dp[0][i] != -1)
//		{
//			dp[0][i] = 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (int i = 1; i <= x1; ++i)
//	{
//		for (int j = 1; j <= y1; ++j)
//		{
//			if (dp[i][j] == -1)
//			{
//				continue;
//			}
//			if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1)
//			{
//				dp[i][j] = 0;
//			}
//			else if (dp[i][j - 1] == -1)
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else if (dp[i - 1][j] == -1)
//			{
//				dp[i][j] = dp[i][j - 1];
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//			}
//		}
//	}
//	cout << dp[x1][y1] << endl;
//}