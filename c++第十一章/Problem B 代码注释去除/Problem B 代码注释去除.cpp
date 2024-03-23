#include<iostream>
#include<string>
using namespace std;
bool is = false;
void show(string s1)
{
	int i = 0;
	for (; i < s1.length(); i++)
	{
		if (is)
		{
			if (s1[i] == '*')
			{
				if (i != s1.length() - 1 && s1[i + 1] == '/')
				{
					string st(s1, i+2, s1.length() - i-2);
					show(st);
					is = false;
					return;
				}
			}
			continue;
		}
		if (s1[i] == '/')
		{
			if (i != s1.length() - 1 && s1[i + 1] == '*')
			{
				is = true;
			}
			if (i != s1.length() - 1 && s1[i + 1] == '/')
			{
				break;
			}

		}
	}
	if (!is)
	{
		string s2(s1, 0, i);
		cout << s2 << endl;
	}
	return;
}

int main()
{
	string s1,s2;

	while (getline(cin, s1))
	{
		show(s1);
	};
}