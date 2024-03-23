#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int arr[6] = { 0,0,0,0,0,0 };
        char f[] = { 'S','C','U','T','e','r' };
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'S' || s[i] == 's')
                arr[0]++;
            if (s[i] == 'C' || s[i] == 'c')
                arr[1]++;
            if (s[i] == 'U' || s[i] == 'u')
                arr[2]++;
            if (s[i] == 'T' || s[i] == 't')
                arr[3]++;
            if (s[i] == 'E' || s[i] == 'e')
                arr[4]++;
            if (s[i] == 'r' || s[i] == 'R')
                arr[5]++;
        }
        while (arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5])
        {
            for (int i = 0; i < 6; i++)
                if (arr[i] != 0)
                {
                    cout << f[i];
                    arr[i]--;
                }
        }
        cout << endl;
    }
}