#include<iostream>
#include<string>
using namespace std;
class MySt
{
public:
	string s;
	MySt operator+(MySt&s1)
	{
		MySt temp;
		temp.s= s + s1.s;
		return temp;
	}
};
int main()
{
	MySt s1,s2;
	while(cin >> s1.s >> s2.s)
	{
		s1 = s1 + s2;
		cout << s1.s << endl;
	}
}