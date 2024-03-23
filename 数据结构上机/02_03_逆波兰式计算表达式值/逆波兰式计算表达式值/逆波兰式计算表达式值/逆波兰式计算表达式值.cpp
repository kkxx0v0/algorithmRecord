#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

int main()
{
	stack<double> st;
	string s;
	getline(cin, s);
	char str[20];
	for (int i = 0; i < s.length(); )
	{
		int j = 0;
		while (isdigit(s[i]) || s[i] == '.')
		{
			str[j++] = s[i];
			str[j] = '\0';
			if (s[++i] == ' ')
			{
				double temp = atof(str);
				st.push(temp);
				j = 0;
				i++;
			}
		}
		double a, b;
		a = st.top();
		st.pop();
		b = st.top();
		st.pop();
		switch (s[i])
		{
		case '+':
			st.push(a + b);
			break;
		case '-':
			st.push(b - a);
			break;
		case '*':
			st.push(a * b);
			break;
		case '/':
			st.push((int)(b / a));
			break;
		default:
			break;
		}
		i += 2;
	}
	cout << st.top() << endl;
}