//#include<iostream>
//#include<queue>
//using namespace std;
//int num[10000]{};
//int is[10000]{};
//int main()
//{
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> num[i];
//		is[i] = 0;
//	}
//	queue<int> q;
//	q.push(0);
//	int max = 0;
//	while (!q.empty())
//	{
//		int temp = q.front();
//		if (temp > max)
//		{
//			max = temp;
//		}
//		q.pop();
//		for (int i = 1; i <= num[temp]; ++i)
//		{
//			if (!is[temp + i])
//			{
//				if (temp + i >= N - 1)
//				{
//					cout << N - 1 << endl;
//					return 0;
//				}
//				q.push(temp + i);
//				is[temp + i] = 1;
//			}
//		}
//	}
//	cout << max << endl;
//	return 0;
//}