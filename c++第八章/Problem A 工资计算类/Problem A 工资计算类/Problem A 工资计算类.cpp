#include<iostream>
#include<string>
using namespace std;
class Employee
{
public:
	int number;
	string name;
	float basicSalary;
	Employee()
	{
		cin >> number >> name;
		basicSalary = 2000.0f;
	}
};
class Salesman :public Employee
{
public:
	float sales;
	static float commrate;
	Salesman()
	{
		cin >> sales;
	}
};
class Salesmanager :public Salesman
{
public:
	float jobSalary;
	Salesmanager()
	{
		jobSalary = 3000.0f;
	}
};
float Salesman::commrate = 0.005f;
int main()
{
	Employee mem1;
	Salesman mem2;
	Salesmanager mem3;
	cout << mem1.name << " " << mem1.number << " " << mem1.basicSalary << endl;
	cout << mem2.name << " " << mem2.number << " " << mem2.basicSalary+mem2.sales*mem2.commrate << endl;
	cout << mem3.name << " " << mem3.number << " " << mem3.basicSalary+mem3.jobSalary+mem3.sales * mem3.commrate << endl;
}