#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			if (temp%m == k)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}