#include<iostream>
#include<vector>
using namespace std;
int h(int x,int n)
{
	return (x % n);
}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = -1;
	}
	vector<int> v;
	int num;
	while (cin>>num)
	{
		v.push_back(num);
		char ch = getchar();
		if (ch == '\n')
		{
			break;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		int temp = h(v[i], n);
		if (p[temp] == -1)
		{
			p[temp] = v[i];
		}
		else
		{
			while (true)
			{
				temp = (temp+1)%n;
				if (p[temp] == -1)
				{
					p[temp] = v[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (p[i]!= -1)
		{
			cout << i << " " << p[i] << endl;
		}
	}
	delete[]p;
}