#include<iostream>
using namespace std;
#define ll long long 
ll A[30000]{}, B[30000]{};
ll N, M;
ll ceil(ll x, ll y)
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
			cnt += ceil(k, B[i]);
		}
	}
	if (cnt <= N * M)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
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
	cout << left << endl;
	return 0;
}