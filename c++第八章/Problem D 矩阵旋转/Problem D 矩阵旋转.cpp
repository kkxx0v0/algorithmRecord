#include<iostream>
using namespace std;
class Node
{
public:
	int x;
	int y;
	int num;
	Node() {};
	Node(int x, int y,int num) :x(x), y(y),num(num) {};
};
Node n[250000];
int main()
{
	int N;
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int num;
			cin >> num;
			n[y * N + x] = Node(x, y,num);
		}
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			n[y * N + x] = Node(N-y-1, x, n[y * N + x].num);
		}
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int i = 0; i < N * N; i++)
			{
				if (n[i].x == x && n[i].y == y)
				{
					cout << n[i].num<<" ";
				}
			}		
		}
		cout << endl;
	}
}