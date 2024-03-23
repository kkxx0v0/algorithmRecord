#include<iostream>
#include<string>
using namespace std;
int MyStrCmp(char* s1, char* s2)
{
	for (int i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] > 64 && s1[i] < 91 && s2[i] > 96 && s2[i] < 123)
			s2[i] -= 32;
		if (s2[i] > 64 && s2[i] < 91 && s1[i] > 96 && s1[i] < 123)
			s1[i] -= 32;
		if (s1[i] < s2[i])
			return 0;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 2;
}
int main()
{
	char s1[21], s2[21];
	while(cin>>s1>>s2)
	{
		int n=MyStrCmp(s1,s2);
		if (n == 0)
			cout << "<" << endl;
		else if (n == 1)
			cout << ">" << endl;
		else if (n == 2)
			cout << "=" << endl;
	}
}