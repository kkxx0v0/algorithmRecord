////#include<iostream>
////using namespace std;
////int main()
////{
////	int t;
////	cin >> t;
////	while (t--)
////	{
////		int l, r;
////		cin >> l >> r;
////		int len = r - l + 1;
////		int* p = new int[len];
////		for (int i = 0; i < len; i++)
////		{
////			p[i] = i + l;
////		}
////	}
////}
//#include<iostream>
//using namespace std;
//int cnt[15] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
////0个数
//int get(int T)
//{
//    int t = 0;
//    while (T % 10 == 0)
//    {
//        T /= 10, t++;
//    }
//    return t;
//}
////求个位数字
//int last(int T)
//{
//    while (T % 10 == 0)
//    {
//        T /= 10;
//    }
//    return T % 10;
//}
////求长度
//int len(int T)
//{
//    while (T % 10 == 0)
//    {
//        T /= 10;
//    }
//    int l = 0;
//    while (T)
//    {
//        T /= 10, l++;
//    }
//    return l;
//}
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int l, r;
//        cin >> l >> r;
//        int ans, minn = 99999999;
//        for (int i = l; i <= r; i += cnt[get(i) + 1])
//        {
//            int minus;
//            if (last(i) == 5)
//                minus = 1;
//            else
//                minus = 0;
//            if (minn > 2 * len(i) - minus)
//            {
//                minn = 2 * len(i) - minus;
//                ans = i;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}