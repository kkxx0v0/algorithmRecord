#include<iostream>
using namespace std;
int l[1000000]{};
int r[1000000]{};
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < t - 1; i++)
	{
		for (int j = 0; j < t - i - 1; j++)
		{
			if (r[j] > r[j + 1])
			{
				int temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				temp = l[j];
				l[j] = l[j + 1];
				l[j + 1] = temp;
			}
		}
	}
	int frt = 0, end = 0;
	int sum = 0;
	for (int i = 0; i < t; i++)
	{
		if (l[i] >= end)
		{
			end = r[i];
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}