#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class String
{
public:
	string s;
	int n;
	String()
	{
		s = "";
		n = 0;
	}
	String(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			s += " ";
		}
	}
	friend istream& operator>>(istream&, String&);
	bool first = true;
	bool isPalindrome()
	{
		string temp=s;
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < n/2+1; i++)
		{
			if (this->s[i] != temp[i])
			{
				first = false;
			}
		}
		if (first)
		{

		}
	}
};
istream& operator>>(istream& input, String& A)
{
	for (int i = 0; i < A.s.length(); i++)
	{
		input >> A.s[i];
	}
	return input;
}
int main() {

	int n, m;
	while (cin >> n) {
		String s1(n);
		cin >> s1;

		cout << s1.isPalindrome() << endl;

		cin >> m;
		String s2(m);
		cin >> s2;

		cout << s2.isIsomorphic(s1) << endl;
	}
	return 0;
}