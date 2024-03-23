#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	queue <int> Q;
	for (int i = 0; i < n; i++)
	{
		Q.push(i);
	}
	for (int i = 0; Q.size()!=1; )
	{
		if (i==m-1)
		{
			Q.pop();
			i = 0;
		}
		else
		{
			int num = Q.front();
			Q.pop();
			Q.push(num);
			i++;
		}
	}
	cout << Q.front() << endl;
}