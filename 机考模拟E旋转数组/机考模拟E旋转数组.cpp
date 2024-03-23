#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int k;
		cin >> k;
		while (k--)
		{
			int temp = arr[n-1];
			for (int i = n-1; i >0; i--)
				arr[i] = arr[i - 1];
			arr[0] = temp;
		}
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
			if (i != n-1)
				cout << " ";
		}
		cout << endl;
	}
}