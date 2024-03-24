#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec;
struct BST
{
	struct BinNode
	{
		int data;
		BinNode* lc;
		BinNode* rc;
		BinNode(int Data, BinNode* Lc = nullptr, BinNode* Rc = nullptr)
		{
			this->data = Data;
			this->lc = Lc;
			this->rc = Rc;
		}
	};
	BinNode* root;
	BST()
	{
		root = NULL;
	}
	BinNode* insert(BinNode* root, int num)
	{
		if (root == NULL)
		{
			return new BinNode(num, NULL, NULL);
		}
		if (num < root->data)
		{
			root->lc = insert(root->lc, num);
		}
		if (num > root->data)
		{
			root->rc = insert(root->rc, num);
		}
		return root;
	}
	void print(BinNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		print(root->lc);
		print(root->rc);
		vec.push_back(root->data);
	}
};

int main()
{
	vector<int> v;
	int num;
	while (cin>>num)
	{
		v.push_back(num);
		char c = getchar();
		if (c == '\n')
		{
			break;
		}
	}
	vector<int> v1 = v;
	reverse(v1.begin(), v1.end());
	BST T;
	for (int i = 0; i < v1.size(); i++)
	{
		T.root = T.insert(T.root,v1[i]);
	}
	T.print(T.root);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]!=vec[i])
		{
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}

bool check(int begin, int end)
{
	if (begin == end)
	{
		return true;
	}
	else if (begin > end)
	{
		return false;
	}
	else
	{
		int ll = begin, lr = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (v[i] < v[end])
			{
				lr++;
			}
			else
			{
				break;
			}
		}
		int rl = lr + 1, rr = end - 1;
		return (check(ll, lr) && check(rl, rr));
	}
}