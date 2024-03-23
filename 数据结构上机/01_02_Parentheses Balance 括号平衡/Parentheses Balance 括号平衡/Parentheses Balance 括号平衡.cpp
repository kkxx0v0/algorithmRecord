#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string s;
	int n;
	while (T--)
	{
		bool is = true;
		n = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{		
			if (s[i]=='(')
			{
				n++;
			}
			else if (s[i] == ')')
			{	
				if (n==0)
				{
					is = false;
					break;
				}
				else
				{
					n--;
				}
			}
		}
		if (n==0)
			if (is==false)
			{
				cout << "FALSE\n";
			}
			else
				cout << "TRUE\n";
		else
			cout << "FALSE\n";
	}
}