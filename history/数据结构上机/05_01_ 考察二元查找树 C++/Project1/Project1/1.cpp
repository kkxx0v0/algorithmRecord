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

	//循环实现 交换左右子树打印顺序
	void loop()
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

	//递归实现 交换左右子树指针再层次打印
	void recursion()
	{
		this->recursion_change(this->root);
		this->print();
	}
	void recursion_change(BinNode* &proot)
	{
		if (proot->lc && proot->rc)
		{
			BinNode* temp = proot->lc;
			proot->lc = proot->rc;
			proot->rc = temp;
			recursion_change(proot->lc);
			recursion_change(proot->rc);
		}
	}
	void print()
	{
		queue<BinNode*> q;
		q.push(root);
		while (!q.empty())
		{
			BinNode* temp = q.front();
			q.pop();
			if (temp->lc)
			{
				q.push(temp->lc);
			}
			if (temp->rc)
			{
				q.push(temp->rc);
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
	//p->loop();
	p->recursion();
}