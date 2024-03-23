#include<iostream>
#include<vector>
using namespace std;


struct maxheap
{
	int* Heap;
	int size;
	int len;
	maxheap(vector<int> vec)
	{
		size = len = vec.size();
		Heap = new int[size];
		for (int i = 0; i < size; i++)
		{
			Heap[i] = vec[i];
		}
	}
	~maxheap()
	{
		delete[]Heap;
	}
	void siftdown(int pos)
	{
		while ((!(pos >= len / 2)&&pos<len))
		{
			int j = 2 * pos + 1;
			int rc = 2 * pos + 2;
 			if ((rc< len)&&Heap[j]>Heap[rc])
			{
				j = rc;
			}
			if (Heap[pos]>=Heap[j])
			{
				int temp = Heap[pos];
				Heap[pos] = Heap[j];
				Heap[j] = temp;
			}
			pos = j;
		}
	}
	void buildHeap()
	{
		for (int i = size /2 - 1; i >=0; --i)
		{
			siftdown(i);
		}
		for (int i = 0; i < size; i++)
		{
			cout << Heap[i] << " " ;
		}
		cout << endl;
	}
	void sort()
	{
		for (int i = size -1; i >=0; --i)
		{
			removemin(i+1);
		}
		for (int i = 0; i < size; i++)
		{
			cout << Heap[i] << " ";
		}
		cout << endl;
	}
	void removemin(int i)
	{
		int temp = Heap[0];
		Heap[0] = Heap[i-1];
		Heap[i-1] = temp;
		len--;
		if (i)
			siftdown(0);
	}
};
int main()
{
	vector<int> vec;
	int num;
	while (cin >> num)
	{
		vec.push_back(num);
		char ch = getchar();
		if (ch == '\n')
			break;
	}
	maxheap mh(vec);
	mh.buildHeap();
	mh.sort();
}