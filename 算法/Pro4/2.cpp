//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<long long> w(n + 1);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> w[i];
//    }
//    vector<vector<int>> B(n + 1);
//    for (int i = 1; i <= m; i++)
//    {
//        int l, r;
//        cin >> l >> r;
//        B[l].push_back(-r);
//        B[r].push_back(l);
//    }
//
//    vector<int> LIM(n + 1);
//    int now = 0;
//    for (int i = 1, j = 1; i <= n; i++) 
//    {
//        for (int x : B[i])
//            if (x > 0 && x >= j)
//                now++;
//        while (now > 0 && j <= i) 
//        {
//            for (int x : B[j]) 
//                if (x < 0 && -x <= i)
//                    now--;
//            j++;
//        }
//        LIM[i] = j;
//    }
//
//    vector<long long> f(n + 1);
//    vector<int> q(n + 2);
//    f[0] = 0;
//    f[1] = w[1];
//    int head = 1, tail = 1;
//    q[tail++] = 0;
//    q[tail++] = 1;
//    for (int i = 2; i <= n; i++) 
//    {
//        int lim = LIM[i - 1] - 1;
//        while (q[head] < lim)
//            head++;
//        f[i] = f[q[head]] + w[i];
//        while (head < tail && f[q[tail - 1]] >= f[i])
//            tail--;
//        q[tail++] = i;
//    }
//
//    cout << f[n] << endl;
//    return 0;
//}