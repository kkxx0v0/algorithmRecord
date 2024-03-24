#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int n = 0;
		for (int i = 0; i < s.length() - 2; i++)
		{
			for (int j = 1; j < s.length() - 1; j++)
			{
				for (int k = 2; k < s.length(); k++)
				{
					if (s[i] == 'C' && s[j] == 'H' && s[k] == 'N')
						if (i < j && j < k)
							n++;
				}
			}
		}
		cout << n << endl;
	}
}