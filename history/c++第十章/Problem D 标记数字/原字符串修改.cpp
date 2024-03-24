#include<iostream>
#include<string>
using namespace std;
bool judge(char ch)
{
	if (ch >= 48 && ch <= 57)
	{
		return true;
	}
	return false;
}
int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length()+cnt; i++)
	{
		if (i==0)
		{
			if (judge(s[i]))
			{
				s.insert(i,"*");
				cnt++;
				i++;
			}
		}
		else if ((!judge(s[i - 1])) && judge(s[i]))
		{
			s.insert(i, "*");
			cnt++;
			i++;
		}
		else if ((!judge(s[i])) && judge(s[i-1]))
		{
			s.insert(i, "*");
			cnt++;
			i++;
		}
	}	
	if (judge(s[s.length()-1]))
	{
		s.insert(s.length(), "*");
	}
	cout << s << endl;
	return 0;
}