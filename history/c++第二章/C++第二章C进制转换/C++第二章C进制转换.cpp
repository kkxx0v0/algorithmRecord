#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	//将0~255范围内的十进制数转换为对应的二进制数和十六进制数
	int n;
	while (cin >> n)
	{
		cout << " "<<bitset<8>(n) << " ";
		printf("%02x", n);
		cout << endl;
	}
}