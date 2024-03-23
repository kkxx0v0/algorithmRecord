#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> vec;
		int num;
		while (cin >> num)
		{
			vec.push_back(num);
			char ch = getchar();
			if (ch == '\n')
				break;
		}
		int cnt = 0;
		int temp = vec[vec.size() - 1];
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]<temp)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}