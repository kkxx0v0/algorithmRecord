//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[300], dp[300][300] {};
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        cin >> a[i];
//        a[i + n] = a[i];
//    }
//    for (int len = 2; len <= n; ++len)
//    {
//        for (int i = 1; i + len - 1 < 2 * n; ++i)
//        {
//            int j = i + len - 1;
//            for (int k = i; k < j; k++)
//            {
//                dp[i][j] = max(dp[i][j],
//                    dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
//            }
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        ans = max(ans, dp[i][i + n - 1]);
//    }
//    cout << ans << endl;
//    return 0;
//}