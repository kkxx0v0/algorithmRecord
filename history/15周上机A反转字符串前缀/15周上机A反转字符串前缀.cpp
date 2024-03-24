#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    char r;
    while (cin >> s >> r)
    {
        string sum = "";
        int i = 0;
        for (; s[i] != '\0'; i++)
        {
            sum += s[i];
            if (s[i] == r)
                break;
        }
        if (s[i] == '\0')
            cout << "none" << endl;
        else
        {
            reverse(sum.begin(), sum.end());
            cout << sum;
            i++;
            for (; s[i] != '\0'; i++)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}