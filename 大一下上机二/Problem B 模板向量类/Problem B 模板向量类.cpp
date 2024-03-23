#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyVector
{
public:
    T num;
    int len;
    T* p;
    MyVector()
    {
        len = 0;
        p = nullptr;
    }
    void push_back(T num)
    {
        len++;
        T* temp = new T[len];
        if (len == 1)
        {
            temp[0] = num;
        }
        else
        {
            for (int i = 0; i < len - 1; i++)
            {
                temp[i] = p[i];
            }
            temp[len - 1] = num;
        }
        delete[]p;
        p = temp;
    }
    T pop_back()
    {
        len--;
        return p[len];
    }
    bool empty()
    {
        if (len==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    MyVector<string> ar;
    int num;
    string temp;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        ar.push_back(temp);
    }
    temp = ar.pop_back();
    cout << temp;
    while (!ar.empty()) {
        temp = ar.pop_back();
        cout << " " << temp;
    }
    cout << endl;
    return 0;
}