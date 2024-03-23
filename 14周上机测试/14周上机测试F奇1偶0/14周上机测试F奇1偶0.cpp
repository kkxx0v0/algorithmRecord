#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	while (cin>>a)
	{
		int change=0;
		for (int i = 0; a[i]; i++)
		{
			change *= 10;
			if (a[i] % 2)
				change+=1;
		}
		cout << change << endl;
	}
}