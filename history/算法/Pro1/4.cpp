#include<iostream>
using namespace std;
#include<queue>
int f[105]{}, d[105]{}, t[105]{};
int n, h;
int cal(int num)
{
	int temp[105]{};
	for (int i = 1; i <= n; i++)
	{
		temp[i] = f[i];
	}
	priority_queue<pair<int, int>> q;
	int cnt = 0;
	int time = h;
	for (int i = 1; i <= num; i++)
	{
		time -= t[i];
	}

	for (int i = 1; i <= num; i++)
	{
		q.push(make_pair(f[i], i));
	}

	for (int i = 0; i < time && !q.empty(); i++)
	{
		int val = q.top().first;
		int num = q.top().second;
		q.pop();
		temp[num] -= d[num];
		q.push(make_pair(temp[num], num));
		cnt += val;
	}
	return cnt;
}
int main()
{
	cin >> n >> h;
	h *= 12;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	for (int i = 2; i <= n; i++)
	{
		cin >> t[i];
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = cal(i);
		if (temp > max)
		{
			max = temp;
		}
	}
	cout << max << endl;
	return 0;
}