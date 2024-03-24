#include <iostream>
using namespace std;
bool n[10] = { 0 };
int main()
{
    int num;
    cin >> num;
	while (!num%10)
	{
		num /= 10;
	}
	while (num)
	{
		if (!n[num%10-1])
		{
			cout << num % 10;
			n[num % 10 - 1] = true;
		}
		num /= 10;
	}
}