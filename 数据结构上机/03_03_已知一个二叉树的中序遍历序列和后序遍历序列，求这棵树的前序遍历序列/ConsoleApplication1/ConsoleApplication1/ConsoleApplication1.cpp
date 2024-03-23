#include<iostream>
#include<string>
using namespace std;

void Print(string s1, string s2)
{
	int len = s1.length();
	if (len == 0)
	{
		return;
	}
	int temp = len-1;
	char ch = s2[temp];
	cout << ch;
	for (unsigned int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == ch)
		{
			temp = i;
			break;
		}
	}
	string s11 = string(s1, 0, temp);
	string s12 = string(s1, temp + 1, len - temp - 1 );
	string s21 = string(s2, 0, temp);
	string s22 = string(s2, temp, len - temp - 1);
	Print(s11, s21);
	Print(s12, s22);
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	Print(s1,s2);
}