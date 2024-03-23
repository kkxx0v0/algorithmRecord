//#include <iostream>
//#include <algorithm>
//using namespace std;
//long long lesson[10000000];
//int read()
//{
//	int x = 0;
//	char c = getchar();
//	while (c < '0' || c > '9')
//	{
//		c = getchar();
//	}
//	while (c >= '0' && c <= '9')
//	{
//		x = x * 10 + c - '0';
//		c = getchar();
//	}
//	return x;
//}
//int main()
//{
//	int N, k;
//	N = read(), k = read();
//	long long sum = 0;
//	for (int i = 0; i < N; i++)
//	{
//		lesson[i] = read();
//	}
//	for (int i = 0; i < N; i++)
//	{
//		sum += lesson[i];
//		lesson[i] -= read();
//	}
//	nth_element(lesson, lesson + k - 1, lesson + N);
//	for (int i = 0; i < k; i++)
//	{
//		sum -= lesson[i];
//	}
//	cout << sum << endl;
//	return 0;
//}