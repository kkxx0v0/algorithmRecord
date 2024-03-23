#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Ternary
{
public:
	int third;
	Ternary()
	{
		third=0;
	}
	Ternary(int num)
	{
		third = 0;
		int cnt = 0;
		while (num)
		{
			third += (num % 3) * pow(10, cnt);
			num /= 3;
			cnt++;
		}
	}
	int operator[](int i)
	{
		return third%10;
	}
	void display()
	{
		cout << third << endl;
	}
	Ternary operator+(Ternary T)
	{
		int temp = third;
		int num1=0, num2=0;
		int cnt = 0;
		while (temp)
		{
			num1 += (temp % 10) * pow(3, cnt);
			temp /= 10;
			cnt++;
		}
		cnt = 0;
		while (T.third)
		{
			num1 += (T.third % 10) * pow(3, cnt);
			T.third /= 10;
			cnt++;
		}
		Ternary temp_T(num1 + num2);
		return temp_T;
	}
};
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	Ternary t1(num1), t2(num2);
	cout << t1[0] << " " << t2[0] << endl;
	t1.display();
	t2.display();
	Ternary t3 = t1 + t2;
	t3.display();
	t1.display();
}