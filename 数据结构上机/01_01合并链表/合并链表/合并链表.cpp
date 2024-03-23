#include<iostream>
using namespace std;

struct ListNode
{ 
	int val;
	ListNode* next;
	ListNode()
	{
		next = NULL;
	}
};

ListNode* CreateList(int n)
{
	ListNode* head = new ListNode;
	ListNode* temp = head;
	ListNode* p;
	for (int i = 0; i < n; i++)
	{
		p = new ListNode;
		cin >> p->val;
		temp->next = p;
		temp = p;
	}
	return head;
}

void ShowList(ListNode* head)
{
	if (head==NULL)
	{
		cout << "NULL\n";
		return;
	}
	while (head->next)
	{
		cout << head->next->val<<" ";
		head = head->next;
	}
	cout << endl;
}

ListNode* Link(ListNode* head1, ListNode* head2)
{
	ListNode* HEAD;
	if ((!head1) && (!head2))
	{
		return NULL;
	}
	else if ((!head1) && head2)
	{
		HEAD = head2;
	}
	else if (head1 && (!head2))
	{
		HEAD = head1;
	}
	else
	{
		int len = 0;
		HEAD = new ListNode;
		ListNode* p = HEAD;
		head1 = head1->next;
		head2 = head2->next;
		while (head1 && head2)
		{
			ListNode* temp;
			if (head1->val >= head2->val)
			{
				temp = head2;
				head2 = head2->next;
				p->next = temp;
				p = p->next;
			}
			else if (head1->val < head2->val)
			{
				temp = head1;
				head1 = head1->next;
				p->next = temp;
				p = p->next;
			}
		}
		if (head1)
		{
			p->next = head1;
		}
		else if (head2)
		{
			p->next = head2;
		}
	}
	return HEAD;
}

int main()
{
	int N1, N2;
	while (cin >> N1 >> N2)
	{
		ListNode* head1 = NULL, * head2 = NULL;
		if (N1)
		{
			head1 = CreateList(N1);
		}
		if (N2)
		{
			head2 = CreateList(N2);
		}
		ListNode* HEAD = Link(head1, head2);
		ShowList(HEAD);
	}
}