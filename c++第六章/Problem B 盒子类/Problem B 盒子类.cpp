#include<iostream>
using namespace std;
class Box
{
public:
	int length;
	int width;
	int height;
	Box()
	{
		cin>>length>>width>>height;
	}
	void setBox(int a,int b,int c)
	{
		length=a;
		width=b;
		height=c;
	}
	int volume()
	{
		int v = length * width * height;
		return v;
	}
};
int main()
{
	Box MyBox;
	cout << MyBox.volume() << endl;
	int a, b, c;
	while (cin>>a>>b>>c)
	{
		MyBox.setBox(a,b,c);
		cout << MyBox.volume() << endl;
	}
	
}