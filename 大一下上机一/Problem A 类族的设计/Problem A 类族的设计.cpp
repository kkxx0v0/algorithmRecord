#include<iostream>
using namespace std;
class Point
{
public:
    int x;
    int y;
};
class Circle :public Point
{
public:
    int r;
    virtual float area()
    {
        return 3.14 * r * r;
    }
    float perimeter()
    {
        return 6.28 * r;
    }
};
class Cylinder:public Circle
{
public:
    int h;
    Cylinder()
    {

    }
    Cylinder(int x, int y, int r, int h)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->h = h;
    }
    void setHeight(int h)
    {
        this->h = h;
    }
    void setRadius(int r)
    {
        this->r = r;
    }
    void setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    virtual float area()
    {
        return perimeter() * (r + h);
    }
    float volume()
    {
        return Circle::area() * h;
    }
};
int main()
{
    int x, y, r, h;
    cin >> x >> y >> r >> h;
    Cylinder cy1(x, y, r, h);
    cout << cy1.area() << " " << cy1.volume() << endl;
    cin >> x >> y >> r >> h;
    cy1.setHeight(h);
    cy1.setRadius(r);
    cy1.setPoint(x, y);
    cout << cy1.area() << " " << cy1.volume() << endl;
    return 0;
}