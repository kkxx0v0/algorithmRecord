#include<iostream>
using namespace std;
int main()
{
	//输入平面上某点的横坐标x和纵坐标y
	//判断该点是否在横纵坐标都为[-2,2]的方块区域内
	int x, y;
	while (cin >> x >> y)//循环获取测试用例
	{
		if (x >= -2 && x <= 2 && y >= -2 && y <= 2)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}