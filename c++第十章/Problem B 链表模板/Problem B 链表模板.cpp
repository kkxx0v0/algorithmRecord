#include<iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T num;
	Node<T>* next;
	Node()
	{
		next = NULL;
	}
	Node* CreateList()
	{
		Node* head,*p;
		head = new Node;
		p = head;
		for (int i = 0; i < 6; i++)
		{
			cin >> p->num;
			if (i < 5)
			{
				p->next = new Node;
				p->next->next = NULL;
				p = p->next;
			}
			
		}
		return head;
	}
	void show(Node* head)
	{
		while (head)
		{
			cout << head->num <<" ";
			head = head->next;
		}
		cout << endl;
	}
};
int main()
{
	Node<int>* head = NULL;
	head=head->CreateList();
	head->show(head);
}