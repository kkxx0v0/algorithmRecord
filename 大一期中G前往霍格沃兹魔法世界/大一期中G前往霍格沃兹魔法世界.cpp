#include<iostream>
using namespace std;
int main()
{
	int N;
	int x, y;
	cin >> N;
	while (N--)
	{
		int h = 11, m = 0, s = 0;
		cin >> x >> y;
		y *= 60;
		h += ((x + y) / 3600);
		m+= ((x + y) / 60 - ((x + y) / 3600)*60);
		s += ((x + y) % 60);
		if (h >= 18 && h < 22)
			cout << "Yes";
		else cout << "No";
		cout << "," << (h%24) << "h:" << m << "m:" << s << "s" << endl;
	}
	return 0;
}