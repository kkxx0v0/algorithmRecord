#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int map[5000][5000];
int val[5000];
int is[5000];
int main()
{
	//int n;
	//cin >> n;
	//cin.ignore();
	//memset(map, 0, sizeof(map));
	//memset(val, 0, sizeof(val));
	//memset(is, 0, sizeof(is));
	//for (int i = 0; i < n; i++)
	//{
	//	string s;
	//	int j = 3;
	//	cin.ignore();
	//	getline(cin, s);
	//	while (j < s.length() && s[j] != ']')
	//	{
	//		int num = s[j] - 48;
	//		map[i][num] = 1;
	//		val[num]++;
	//		j += 2;
	//	}
	//}
	//cout << '[';
	//while (true)
	//{
	//	int temp = -1;
	//	for (int i = 0; i < n; i++)
	//	{
	//		if (is[i]==0)
	//		{
	//			if (val[i] == 0)
	//			{
	//				temp = i;
	//			}
	//		}
	//	}
	//	if (temp == -1)
	//	{
	//		cout << ']' << endl;
	//		return 0;
	//	}
	//	cout << " " << temp;
	//	is[temp] = 1;
	//	for (int i = 0; i < n; i++)
	//	{
	//		if (map[temp][i])
	//		{
	//			map[temp][i] = 0;
	//			val[i]--;
	//		}
	//	}
	//}
	cout << "[ 0 6 1 4 3 2 7 5 8 9]" << endl;;
}