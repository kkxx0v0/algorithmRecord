#include<iostream>
#include<vector>
using namespace std;
void insert_sort(vector<int> &vec) 
{
	int cnt = 0;
	for (int i = 1; i < vec.size(); i++)
		for (int j = i; (j > 0) && (vec[j] < vec[j - 1]); j--)
		{
			int temp = vec[j];
			vec[j] = vec[j - 1];
			vec[j - 1] = temp;
			cnt++;
		}
	cout << cnt << endl;
}
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
		insert_sort(vec);
	}
}