#include<iostream>
using namespace std;
class Rectangle
{
public:
	int length;
	int width;
	Rectangle()
	{
		cin >> length >> width;
	}
	void S()
	{
		cout << length * width << endl;
	}
};
class Rectangular :public Rectangle
{
public:
	int height;
	Rectangular()
	{
		cin >> height;
	}
	void V()
	{
		cout << length * width * height << endl;
	}
};
int main()
{
	Rectangle _1;
	Rectangular _2;
	_1.S();
	_2.V();
}