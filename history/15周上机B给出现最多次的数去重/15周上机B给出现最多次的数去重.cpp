#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int arr[10005] = { 0 };
        int* p = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            arr[p[i]]++;
        }
        int max = 0;
        for (int i = 0; i < 10005; i++)
            if (arr[i] > arr[max])
                max = i;
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] != max)
            {
                sum += p[i];
                cnt++;
            }
        }
        sum += max;
        cnt++;
        printf("%.2lf\n", sum / cnt);
        delete[]p;
    }

}