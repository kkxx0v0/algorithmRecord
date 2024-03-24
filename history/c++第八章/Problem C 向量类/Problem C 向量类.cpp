#include<iostream>
using namespace std;
class Integer 
{ 
public:
	int n; 
};
class Vector:public Integer 
{ 
public: 
	int *v;
	Vector() :v(nullptr) {};
	Vector(int len)
	{
		n = len;
		v = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}
	Vector(const Vector& obj)
	{
		v = obj.v;
	}
	void add(const Vector& v)
	{
		for (int i = 0; i < n; i++)
		{
			if (i)
			{
				cout << " ";
			}
			cout << this->v[i] + v.v[i];
		}
		cout << endl;
	}
	void sub(const Vector& v)
	{
		for (int i = 0; i < n; i++)
		{
			if (i)
			{
				cout << " ";
			}
			cout << this->v[i] - v.v[i];
		}
		cout << endl;
	}
	void multiply(const Vector& v)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum+= this->v[i] * v.v[i];
		}
		cout <<sum<< endl;
	}
}; 
int main()
{
	int len;
	cin >> len;
	Vector v1(len), v2(len);
	v1.add(v2);
	v1.sub(v2);
	v1.multiply(v2);
}