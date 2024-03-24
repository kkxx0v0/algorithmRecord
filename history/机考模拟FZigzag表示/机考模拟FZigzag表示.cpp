#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	while (cin >> a)
	{
		string b = "";
		int n;
		cin >> n;
		int sum = 2 * (n - 1);
		if (n == 1)
		{
			cout << a << endl;
			continue;

		}
		else if (n == 2)
		{
			for (int i = 0;i<size(a); i += 2)
				b += a[i];
			for (int i = 1;i<size(a); i += 2)
				b += a[i];
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < size(a); j += sum)
						b += a[j];
				}
				if (i == n - 1)
				{
					for (int j = n - 1; j < size(a); j += sum)
						b += a[j];
				}
				else
				{
					bool oj=1;
					for (int j = i; j < size(a); (oj == 1) ?(j += (2 * (n - 1 - i))) : (j += (sum - (2 * (n - 1 - i)))))
					{
						b+=a[j];
						oj=!oj;
					}
				}

			}
		}
		cout << b << endl;
	}
	

}