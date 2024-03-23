#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
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
	void print()
	{
		queue<BinNode*> q;
		q.push(root);
		while (!q.empty())
		{
			BinNode* temp = q.front();
			q.pop();
			if (temp->rc)
			{
				q.push(temp->rc);
			}
			if (temp->lc)
			{
				q.push(temp->lc);
			}
			cout << temp->data << " ";
		}
		cout << endl;
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
		{
			break;
		}
	}
	BST* p = new BST;
	for (int i = 0; i < vec.size(); i++)
	{
		p->root = p->insert(p->root, vec[i]);
	}
	p->print();
}