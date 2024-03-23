#include<iostream>
using namespace std;
//----------------------------------------------------------------------------
void pro1()
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
}
//------------------------------------------------------------------------------
int l[1000000]{};
int r[1000000]{};
void pro2()
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
	int frt = 0,end = 0;
	int sum =0;
	for (int i = 0; i < t; i++)
	{
		if (l[i]>=end)
		{
			end = r[i];
			sum++;
		}
	}
	cout << sum << endl;
	return;
}
//----------------------------------------------------------------------------
#define ll long long 
ll A[30000]{},B[30000]{};
ll N, M;
ll ceil(ll x,ll y)
{
	return (x % y) ? (x / y + 1) : (x / y);
}
bool check(ll k)
{
	ll cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > B[i])
		{
			ll num = ceil(k, A[i]);
			if (num > M)
			{
				cnt += M;
				cnt += ceil(k - M * A[i], B[i]);
			}
			else
			{
				cnt += num;
			}
		}
		else
		{
			cnt+=ceil(k, B[i]);
		}
	}
	if (cnt <=N*M)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void pro3()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	ll left = 0, right = 1e18 + 1000;
	while (left + 1 < right)
	{
		ll mid = left + right >> 1;
		if (check(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << left;
}
//--------------------------------------------------------------------------------
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
	priority_queue<pair<int,int>> q;
	int cnt = 0;
	int time = h;
	for (int i = 1; i <= num; i++)
	{
		time -= t[i];
	}

	for (int i = 1; i <= num; i++)
	{
		q.push(make_pair(f[i],i));
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
void pro4()
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
		if (temp>max)
		{
			max = temp;
		}
	}
	cout << max << endl;
}

int main()
{
	//pro1();
	//pro2();
	//pro3();
	pro4();
}