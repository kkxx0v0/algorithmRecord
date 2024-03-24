#include<iostream>
#include<string>
#include<string.h>
#define N 10000000
using namespace std;
bool is[N];
int main_1()
{
	string s;
	cin >> s;
	memset(is, false, N);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]>=48&&s[i]<=57)
		{
			is[i] = true;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (i==0)
		{
			if((i == 0) && is[i])
			{
				cout << '*';
			}
		} 
		else if ((!is[i - 1]) && is[i])
		{
			cout << '*';
		}
		else if (is[i - 1] && !is[i])
		{
			cout << '*';
		}
		cout << s[i];
		if (is[i]&&i== s.length()-1)
		{
			cout << '*';
		}		
	}
	return 0;
}