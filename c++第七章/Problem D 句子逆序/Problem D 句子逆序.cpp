#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1,s2,w;
	s2 = "";
	w = "";
	getline(cin, s1);
	int cnt = 0;
	for (int i = s1.length()-1; i >=0 ; --i)
	{
		if (s1[i]!=' ')
		{
			w += s1[i];
		}
		else
		{
			reverse(w.begin(), w.end());
			s2 += w;
			s2 += ' ';
			w = "";
		}
	}
	reverse(w.begin(), w.end());
	s2 += w;
	cout << s2;
}