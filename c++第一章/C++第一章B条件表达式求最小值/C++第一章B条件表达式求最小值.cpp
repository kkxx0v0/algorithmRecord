#include<iostream>
using namespace std;
int main()
{
	//输入三个整数，求其中最小值
	//要求使用条件表达式 (  )? : 
	int a, b, c;
	cin >> a >> b >> c;
	int min = a;
	min = (a < b ? a : b) < c ? (a < b ? a : b) : c;//两个条件表达式嵌套
	cout << min << endl;
	return 0;
}