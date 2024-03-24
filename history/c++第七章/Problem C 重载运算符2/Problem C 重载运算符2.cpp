#include<iostream>
using namespace std;
class V
{
public:
	int* p;
	int cnt;
	V()
	{
		p = nullptr;
	}
	V(int n)
	{
		cnt = n;
		p = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
	}
	V operator+(const V& v)
	{
		V temp;
		temp.cnt = cnt;
		temp.p = new int[cnt];
		for (int i = 0; i < cnt; i++)
		{
			temp.p[i]=this->p[i] + v.p[i];
		}
		return temp;
	}
	V operator-(const V& v)
	{
		V temp;
		temp.cnt = cnt;
		temp.p = new int[cnt];
		for (int i = 0; i < cnt; i++)
		{
			temp.p[i] = this->p[i] - v.p[i];
		}
		return temp;
	}
};
void show(V v)
{
	for (int i = 0; i < v.cnt; i++)
	{
		if (i||i== v.cnt-1)
		{
			cout << " ";
		}
		cout << v.p[i];
	}
	cout << endl;
}
int main()
{
	char ch;
	while (cin>>ch)
	{
		int n;
		cin >> n;
		V v1(n), v2(n);
		switch (ch)
		{
		case '+':
			show(v1 + v2);
			break;
		case '-':
			show(v1 - v2);
			break;
		case '*':
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += (v1.p[i] * v2.p[i]);
			}
			cout << sum << endl;
			break;
		}
		default:
			break;
		}
	}
}