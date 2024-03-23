#include<iostream>
using namespace std;
class Vehicle
{
public:
    int num;
    double kg;
    virtual void display() = 0;
};
class Car:public Vehicle
{
public:
    Car()
    {

    }
    Car(int num, double kg)
    {
        this->num = num;
        this->kg = kg;
    }
    virtual void display()
    {
        cout << num * 8 + kg * 2 << endl;
    }
};
class Truck :public Vehicle
{
public:
    Truck()
    {

    }
    Truck(double kg)
    {
        this->kg = kg;
    }
    virtual void display()
    {
        cout << kg * 5 << endl;
    }
};
class Bus :public Vehicle
{
public:
    Bus()
    {

    }
    Bus(int num)
    {
        this->num = num;
    }
    virtual void display()
    {
        cout << num * 3 << endl;
    }
};
int main()
{
    Vehicle* pd[10];
    int t, num, i = 0;
    double kg;
    cin >> t;
    while (t) {
        if (t == 1) {
            cin >> num >> kg;
            pd[i] = new Car(num, kg);
        }
        else if (t == 2) {
            cin >> kg;
            pd[i] = new Truck(kg);
        }
        else if (t == 3) {
            cin >> num;
            pd[i] = new Bus(num);
        }
        pd[i]->display();
        i++;
        cin >> t;
    }
    delete* pd;
    return 0;
}