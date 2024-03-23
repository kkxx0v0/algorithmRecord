#include<iostream>
#include<iomanip>
using namespace std;
template<typename T>
T average(T _1,T _2,T _3)
{
	return (_1 + _2 + _3) / 3;
}
int main()
{
	int I[3];
	double D[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> I[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> D[i];
	}
	cout << average(I[0], I[1], I[2]) << endl;
	cout << fixed << setprecision(3)<< average(D[0], D[1], D[2]) << endl;

}