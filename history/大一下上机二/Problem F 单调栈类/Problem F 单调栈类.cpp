#include <iostream>
using namespace std;
void Mysort(int p[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = len-1; j > i; --j)
        {
            if (p[j-1]>p[j])
            {
                int temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
        }
    }
}
class SStack
{
public:
    int len;
    int *p;
    SStack()
    {
        len = 0;
        p = NULL;
    }
    void push(int num)
    {
        len++;
        int* temp = new int[len];
        if (len==1)
        {
            temp[0] = num;
        }
        else
        {
            for (int i = 0; i < len-1; i++)
            {
                temp[i] = p[i];
            }
            temp[len - 1] = num;
        }
        if (p!=NULL)
        {
            delete[]p;
        }     
        Mysort(temp, len);
        p = temp;
    }
    void pop()
    {
        len--;
    }
    int top()
    {
        return p[len-1];
    }
    bool isEmpty()
    {
        if (!len)
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
    SStack stack = SStack();
    int n;
    int num;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> num;
            stack.push(num);
        }
        while (!stack.isEmpty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;
    }
    return 0;
}