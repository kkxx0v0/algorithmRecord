#include<iostream>
using namespace std;
class Circle
{
public:
	int radius;
	virtual int area() { return NULL; };
	virtual int volume() { return NULL; };
};
class Sphere :public Circle
{
public:
	virtual int area()
	{
		return 12 * radius * radius;
	}
	virtual int volume()
	{
		return 4 * radius * radius * radius;
	}
};
class Column :public Circle
{
public:
	int height;
	virtual int area()
	{
		return 6 * radius * radius + 6 * radius * height;
	}
	virtual int volume()
	{
		return 3 * radius * radius * height;
	}
};
int main()
{
	Sphere _1;
	Column _2;
	cin >> _1.radius >> _2.height;
	_2.radius = _1.radius;
	cout << _1.volume() << " " << _1.area() << " " << _2.volume() << " " << _2.area() << " " << endl;
}