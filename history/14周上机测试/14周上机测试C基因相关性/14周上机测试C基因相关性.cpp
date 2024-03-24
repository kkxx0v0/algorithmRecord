#include<iostream>
#include<string>
using namespace std;
int main()
{
	float n;
	string a, b;
	while (cin >> n >> a >> b)
	{
		int same=0;
		int len = 0;
		for (int i = 0; a[i]; i++)
		{
			len++;
			if (a[i] == b[i])
				same++;
		}
		if (((float)same / len) >= n)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}