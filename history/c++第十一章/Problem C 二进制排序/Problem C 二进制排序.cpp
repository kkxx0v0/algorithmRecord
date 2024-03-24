#include<iostream>
#include<cmath>
using namespace std;
void bubbleSort(int a[],int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char num[32];
	for (int i = 0; i < 32; i++)
	{
		cin >> num[i];
	}
	int n[4]={0,0,0,0};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 7; j >=0; --j)
		{
			n[i] += (((int)num[i * 8 + (7 - j)]-48) * pow(2, j));
		}
	}
	bubbleSort(n,4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 7; j >= 0; --j)
		{
			cout << n[i] / (int)pow(2, j);
			n[i] %= (int)pow(2, j);
		}
	}
	return 0;
}