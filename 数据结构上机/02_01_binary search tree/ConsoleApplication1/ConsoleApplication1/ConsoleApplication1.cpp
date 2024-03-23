#include<iostream>
#include<string>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
struct BST
{
	struct BinNode
	{
		int data;
		BinNode* lc;
		BinNode* rc;
		BinNode(int Data, BinNode* Lc, BinNode* Rc)
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
	int TreeHight(BinNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else
			return 1 + max(TreeHight(root->lc), TreeHight(root->rc));
	}
	BinNode* insert(BinNode* root, const int num)
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
};

int main()
{
	vector<int> vec;
	int num;
	while (cin >> num)
	{
		vec.push_back(num);
		char ch = getchar();
	}
	BST* p = new BST;
	for (int i = 0; i < vec.size(); i++)
	{
		p->root = p->insert(p->root, vec[i]);
	}
	cout << p->TreeHight(p->root) << endl;
}