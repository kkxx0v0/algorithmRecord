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
};
class ExtTime:public Time
{
public:
    int TimeZone;
    ExtTime()
    {
        TimeZone = 0;
    }
    ExtTime(int h, int m, int s, int TimeZone)
    {
        this->h = h;
        this->m = m;
        this->s = s;
        if ((h == 24) && (m == 0) & (s == 0))
        {
            this->h = 0;
        }
        this->TimeZone = TimeZone;
    }
    void set(int h, int m, int s,int TimeZone)
    {
        this->h = h;
        this->m = m;
        this->s = s;
        if ((h == 24) && (m == 0) & (s == 0))
        {
            this->h = 0;
        }
        this->TimeZone = TimeZone;
    }
    void display()
    {
        cout << "(GMT";
        if (TimeZone>0)
        {
            cout << "+" << TimeZone;
        }
        if (TimeZone < 0)
        {
            cout <<  TimeZone;
        }
        cout << ") ";
        if (h < 10)
        {
            cout << 0;
        }
        cout << h << ":";
        if (m < 10)
        {
            cout << 0;
        }
        cout << m << ":";
        if (s < 10)
        {
            cout << 0;
        }
        cout << s << endl;
    }
    void increment()
    {
        s++;
        if (s >= 60)
        {
            s -= 60;
            m++;
            if (m >= 60)
            {
                m -= 60;
                h++;
                if (h >= 24)
                {
                    h -= 24;
                }
            }
        }
    }
    bool equal(ExtTime& other_time)
    {
        if (h- TimeZone == other_time.h- other_time.TimeZone && m == other_time.m && s == other_time.s)
        {
            return true;
        }
        return false;
    }
    bool less_than(ExtTime& other_time)
    {
        if (h - TimeZone < other_time.h - other_time.TimeZone)
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
enum TimeZone {
    W12 = -12, W11, W10, W9, W8, W7, W6, W5, W4, W3, W2, W1,
    GMT, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12
};
int main()
{
    ExtTime t1;
    t1.display();
    int z1, h1, m1, s1, z2, h2, m2, s2;
    cin >> z1 >> h1 >> m1 >> s1;
    cin >> z2 >> h2 >> m2 >> s2;
    ExtTime t2(h2, m2, s2, TimeZone(z2));
    t2.display();
    t1.set(h1, m1, s1, TimeZone(z1));
    t1.display();
    if (t1.equal(t2))
        cout << "t1==t2" << endl;
    else
        cout << "t1!=t2" << endl;
    t1.increment();
    t1.display();
    if (t2.less_than(t1))
        cout << "t2 earlier than t1" << endl;
    else
        cout << "t2 is not earlier than t1" << endl;
}