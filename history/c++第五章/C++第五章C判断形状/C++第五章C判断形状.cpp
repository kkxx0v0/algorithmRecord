#include<iostream>
#include<cmath>
using namespace std;
struct xy
{
	int x;
	int y;
};
int Z(xy d1,xy d2)
{
	return abs(pow(d1.x- d2.x, 2)) + abs(pow(d1.y- d2.y, 2));
}
int main()
{
	int n = 3;
	xy d[4];
	while (n--)
	{
		cin >> d[0].x >> d[0].y >> d[1].x >> d[1].y >> d[2].x >> d[2].y >> d[3].x >> d[3].y;
		if ((Z(d[0], d[1]) == Z(d[2], d[3])) && (Z(d[0], d[2]) == Z(d[1], d[3])) && (Z(d[0], d[3]) == Z(d[1], d[2])))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}