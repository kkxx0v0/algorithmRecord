#include<iostream>
using namespace std;
class Time
{
public:
	int h;
	int m;
	int s;
	Time()
	{
		h = 0;
		m = 0;
		s = 0;
	}
	Time(int h, int m, int s)
	{
		this->h = h;
		this->m = m;
		this->s = s;
		if ((h == 24) && (m == 0) & (s == 0))
		{
			this->h = 0;
		}
	}
	void set(int h, int m, int s)
	{
		this->h = h;
		this->m = m;
		this->s = s;
		if ((h == 24) && (m == 0) & (s == 0))
		{
			this->h = 0;
		}
	}
	void increment()
	{
		s++;
		if (s>=60)
		{
			s -= 60;
			m++;
			if (m>=60)
			{
				m -= 60;
				h++;
				if (h>=24)
				{
					h -= 24;
				}
			}
		}
	}
	void display()
	{
		if (h<10)
		{
			cout << 0 ;
		}
		cout << h << ":";
		if (m < 10)
		{
			cout << 0 ;
		}
		cout << m << ":";
		if (s < 10)
		{
			cout << 0;
		}
		cout << s << endl;
	}
	bool equal(Time& other_time)
	{
		if (h== other_time.h && m == other_time.m && s == other_time.s)
		{
			return true;
		}
		return false;
	}
	bool less_than(Time& other_time)
	{
		if (h < other_time.h)
		{
			return true;
		}
		else if (h > other_time.h)
		{
			return false;
		}
		else
		{
			if (m < other_time.m)
			{
				return true;
			}
			else if (m > other_time.m)
			{
				return false;
			}
			else
			{
				if (s < other_time.s)
				{
					return true;
				}
				else if (s >= other_time.s)
				{
					return false;
				}
			}
		}
	}
};
int main()
{
	Time t1;
	t1.display();
	int h1, m1, s1, h2, m2, s2;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	Time t2(h2, m2, s2);
	t2.display();
	t1.set(h1, m1, s1);
	t1.display();
	if (t1.equal(t2))
		cout << "t1==t2" << endl;
	else
		cout << "t1!=t2" << endl;
	if (t2.less_than(t1))
		cout << "t2 earlier than t1" << endl;
	else
		cout << "t2 is not earlier than t1" << endl;
	t1.increment();
	t1.display();
}