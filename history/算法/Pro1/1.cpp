#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		int cnt = 0;
		cin >> x >> y;
		while (x != y)
		{
			if (x > y)
			{
				y = y + 2;
				cnt++;
			}
			else
			{
				x++;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}