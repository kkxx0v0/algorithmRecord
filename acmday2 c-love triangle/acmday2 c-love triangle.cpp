#include<iostream>
#include<string.h>
using namespace std;
int map[5005];
int main()
{
	int n;
	cin >> n;
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; i++)
		cin >> map[i];
	int yes=0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 1;
		int init=i,x=i,y;
		while (cnt <= 3 && x <= n)
		{
			y = map[x];
			x = y;
			cnt++;
		}
		if (x == init)
		{
			yes = 1;
			cout << "YES" << endl;
			break;
		}
	}
	if (!yes)
		cout << "NO" << endl;
}