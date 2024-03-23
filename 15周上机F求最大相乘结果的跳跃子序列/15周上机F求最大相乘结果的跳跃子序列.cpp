#include<iostream>
using namespace std;
int main()
{
	int N;
	while (cin >> N)
	{
		while (N--)
		{
			int n;
			cin >> n;
			int* p = new int[n];
			for (int i = 0; i < n; i++)
				cin >> p[i];
			long long max1 = 0;//Sn, (-10<=Si<=10,  i=3,4,...,22)

			//法一选择从i到j的子序列
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j+=2)
				{
					long long sum = 1;//注意最大有十的22次方
					for (int k = i; k <= j; k+=2)
						sum *= p[k];
					if (sum>max1)
						max1 = sum;
				}
			}

			long long max2 = 0;
			//法二选择从i开始的各个子列
			for (int i = 0; i < n; i++)
			{
				long long sum = 1;
				for (int j = i; j < n; j += 2)
				{
					sum *= p[j];
					if (sum > max2)
						max2 = sum;
				}
			}

			cout << max1<< " "<<max2 << endl;
			delete[]p;
		}
	}
}