#include<iostream>
using namespace std;
const int M = 3, N = 3, P = 2;
int main()
{
	int a[M][N], b[N][P], c[M][P] = {0};
	cout << "cin>>a:" << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
				cin>>a[i][j];
	cout << endl;
	cout << "cin>>b:" << endl;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < P; j++)
			cin >> b[i][j];
	cout << endl << "a✖b=" << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < P; j++)
			for (int k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < P; j++)
			cout << c[i][j]<<"\t";
		cout << endl;
	}
	cout << endl;

}
