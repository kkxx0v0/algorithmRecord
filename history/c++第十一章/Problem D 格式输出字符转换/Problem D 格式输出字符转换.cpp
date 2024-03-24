#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt = s.length() / 16;
	for (int i = 1; i <= cnt; i++)
	{
		cout << setw(8) << setfill('0') << setbase(16) << i * 16 << "  ";
		for (int j = 0; j < 16; j++)
		{			
			cout << (int)s[i * 16 - 16 + j] << " ";
		}
		cout << " ";
		for (int j = 0; j < 16; j++)
		{
			cout << s[i * 16 - 16 + j];
		}
		cout << endl;
	}
}