#include <iostream>
using namespace std;
struct dang
{
	int m1, m2;
};
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		dang* p = new dang[N];
		for (int i = 0; i < N; i++)
		{
			cin >> p[i].m1 >> p[i].m2;
		}
		for (int i = 0; i < M; i++)
		{
			int k;
			cin >> k;
			int* arr = new int[k];
			for (int j = 0; j < k; j++)
			{
				cin >> arr[j];
			}
			bool is = true;
			for (int j = 0; j < k; j++)
			{
				for (int t = 0; t < N; t++)
				{
					if (arr[j] == p[t].m1)
					{
						for (int h = 0; h < k; h++)
						{
							if (arr[h] == p[t].m2)
							{
								if(is)
									cout << "No\n";
								is = false;
								break;
							}
						}
						break;
					}
				}
			}
			if (is)
				cout << "Yes\n";
		}
	}
}
