#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int T;
	cin >> T;
	string s;
	while (T--)
	{
		map<string, int> m;
		int M, N;//M是总词数 N是搜索几个词
		cin >> M >> N;
		for (int i = 0; i < M; i++)
		{
			cin >> s;
			auto it = m.find(s);
			if (it != m.end())
			{
				it->second++;
			}
			else
				m.insert(pair<string, int>(s, 1));
		}
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			auto it = m.find(s);
			if (it != m.end())
			{
				cout << it->second << " ";
			}
			else
				cout << 0 << " ";
			
		}
		cout << endl;
	}
}