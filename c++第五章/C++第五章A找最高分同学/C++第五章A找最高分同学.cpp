#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name;
	int score;
};
int main()
{
	Student a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i].name >> a[i].score;
	}
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i].score > a[max].score)
		{
			max = i;
		}
	}
	cout << a[max].name;
}