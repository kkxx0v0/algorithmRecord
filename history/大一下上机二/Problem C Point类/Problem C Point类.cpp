#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point
{
public:
    double x,y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double r()
    {
        return pow(pow(x, 2) + pow(y, 2), 0.5);
    }
    double distance(const Point& p)
    {
        return pow(pow(x-p.x, 2) + pow(y-p.y, 2), 0.5);
    }
    Point relative(const Point& p)
    {
        Point temp;
        temp.x = x - p.x;
        temp.y = y - p.y;
        return temp;
    }
    bool is_above_left(const Point& p)
    {
        if ((x<p.x)&&(y>p.y))
        {
            return true;
        }
        return false;
    }
};
int main()
{
    double x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    Point p1, p2(x2, y2), p3(x3, y3);
    cout << fixed << setprecision(2) << p2.r() << endl;
    cout << "The distance between p3 and p2 is " << fixed << setprecision(2) << p3.distance(p2) << endl;
    Point p4 = p2.relative(p3);
    cout << fixed << setprecision(2) << "p4:(" << p4.x << "," << p4.y << ")" << endl;
    cout << "Is p2 is above left of p3?:" << p2.is_above_left(p3) << endl;
}