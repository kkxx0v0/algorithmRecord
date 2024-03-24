#include<iostream>
#include<ctype.h>
#include<queue>
using namespace std;

struct Tree
{
	struct treenode
	{
		char ch;
		treenode* lc;
		treenode* rc;
		treenode(char C)
		{
			this->ch = C;
			lc = NULL;
			rc = NULL;
		}
	};
	treenode* root;
	Tree(char c)
	{
		root = new treenode(c);
	}
	bool insert(treenode* root, char c)
	{
		if (islower(root->ch)) {
			if (root->lc != NULL) {
				if (insert(root->lc, c)) {
					return true;
				}
			}
			else {
				root->lc = new treenode(c);
				return true;
			}
			if (root->rc != NULL) {
				if (insert(root->rc, c)) {
					return true;
				}
			}
			else {
				root->rc = new treenode(c);
				return true;
			}
		}
		else {
			return false;
		}
		return false;
	}
	void show(treenode* root)
	{
		queue<treenode*> q;
		q.push(root);
		while(!q.empty())
		{
			treenode* temp = q.front();
			cout << temp->ch;
			if (temp->lc)
				q.push(temp->lc);
			if (temp->rc)
				q.push(temp->rc);
			q.pop();
		}
		cout << endl;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		Tree* p = new Tree(s[0]);
		for (int i = 1; i < s.length(); i++)
		{
			p->insert(p->root, s[i]);
		}
		p->show(p->root);
	}
}