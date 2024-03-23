#include<iostream>
#include<string>
using namespace std;
class Teacher
{
public:
    string name;
    const int salary = 2000;
    char level;
    int time;
    Teacher()
    {
        cin >> name >> level >> time;
    }
    int show()
    {
        int money = 0;;
        switch (level)
        {
        case '1':
            money = 50;
            break;
        case '2':
            money = 30;
            break;
        case '3':
            money = 20;
            break;
        default:
            break;
        }
        return salary + money * time;
    }
};
int main()
{
    Teacher* T[4];
    int add = 0, average = 0, max = 0, min = 100000000;
    for (int i = 0; i < 4; i++)
    {
        T[i] = new Teacher;
        add += (T[i]->show());
        if (T[i]->show()>max)
        {
            max = T[i]->show();
        }
        if (T[i]->show() < min)
        {
            min = T[i]->show();
        }
    }
    average = add / 4;
    cout << add << endl << average << endl << max << endl << min << endl;
}