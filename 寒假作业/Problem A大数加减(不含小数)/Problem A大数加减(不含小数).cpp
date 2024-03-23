#include<iostream>
#include<string>
using namespace std;

struct Node
{
	char ch;
	Node* next;
};

Node* Reverse(Node* head)
{
	Node* p, * q;
	p = head->next;
	q = p;
	p = p->next;
	q->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
	return head;
}

void ShowNode(Node* head)
{
	if (head->ch == '+')
	{
		head = head->next;
	}
	while (head)
	{
		cout << head->ch;
		head = head->next;
	}
	cout << endl;
}

bool IsBig(Node* num1, Node* num2)
{
	Node* p1 = num1, * p2 = num2;
	int len1=0,len2=0;
	while (p1)
	{
		len1++;
		p1 = p1->next;
	}
	while (p2)
	{
		len2++;
		p2 = p2->next;
	}
	p1 = num1;
	p2 = num2;
	if (len1 > len2)
		return true;
	else if (len1 < len2)
	{
		return false;
	}
	else
	{
		num1=Reverse(num1);
		num2=Reverse(num2);
		ShowNode(num1);
		ShowNode(num2);
		while (num1)
		{
			if (num1->ch >= num2->ch)
				;
			else
			{
				p1 = Reverse(p1);
				p2 = Reverse(p2);
				ShowNode(p1);
				ShowNode(p2);
				return false;
			}
			num1 = num1->next;
			num2 = num2->next;
		}
		p1 = Reverse(p1);
		p2 = Reverse(p2);
		return true;
	}
}

Node * CreatList(Node * head,string s)
{
	head = new Node;
	head->next = NULL;
	if (s[0] == '-')
	{
		head->ch = '-';
	}
	else
	{
		Node* p;
		p = new Node;
		p->ch = s[0];
		p->next = head->next;
		head->next = p;
		head->ch = '+';
	}
	int len = s.length();
	for (int i = 1; i < len; i++)
	{
		Node* p;
		p = new Node;		
		p->ch = s[i];
		p->next = head->next;
		head->next = p;
	}
	return head;
}

Node* Add(Node* num1,Node* num2)
{
	num1 = num1->next;
	num2 = num2->next;
	Node* head;
	head = new Node;
	head->ch = '+';
	head->next = NULL;
	int cnt = 0;
	int n = 0;
	while (num1&&num2)
	{
		if (n==3)
		{
			Node* p;
			p = new Node;
			p->ch = ',';
			p->next = head->next;
			head->next = p;
			n = 0;
		}
		Node* p;
		p = new Node;
		if (num1->ch==','&& num2->ch == ',')
		{
			num1 = num1->next;
			num2 = num2->next;
			continue;
		}
		if ((int)num1->ch-48 + (int)num2->ch-48+cnt>=10)
		{			
			p->ch = (char)((int)num1->ch - 48 + (int)num2->ch - 48 + cnt - 10+48);
			cnt = 1;
		}
		else
		{
			p->ch = (char)((int)num1->ch - 48 + (int)num2->ch - 48 + cnt + 48);
			cnt = 0;
		}
		num1 = num1->next;
		num2 = num2->next;
		p->next = head->next;
		head->next = p;
		n++;
	}
	if (num1)
	{
		while (num1)
		{
			Node* p;
			p = new Node;
			if (num1->ch == ',')
			{
				num1 = num1->next;
				continue;
			}
			if ((int)num1->ch - 48 + cnt >= 10)
			{
				p->ch = (char)((int)num1->ch - 48 + cnt - 10 + 48);
				cnt = 1;
			}
			else
			{
				p->ch = (char)((int)num1->ch - 48 + cnt + 48);
				cnt = 0;
			}
			num1 = num1->next;
			p->next = head->next;
			head->next = p;
		}		
	}
	else if (num2)
	{
		while (num2)
		{
			Node* p;
			p = new Node;
			if (num2->ch == ',')
			{
				num2 = num2->next;
				continue;
			}
			if ((int)num2->ch - 48 + cnt >= 10)
			{
				p->ch = (char)((int)num2->ch + cnt - 10);
				cnt = 1;
			}
			else
			{
				p->ch = (char)((int)num2->ch + cnt);
				cnt = 0;
			}
			num2 = num2->next;
			p->next = head->next;
			head->next = p;
		}
	}
	return head;
}

Node* Sub(Node* num1, Node* num2)
{
	num1 = num1->next;
	num2 = num2->next;
	bool big = IsBig(num1, num2);
	Node* head;
	head = new Node;
	head->ch = '+';
	head->next = NULL;
	int n = 0;
	int cnt = 0;
	while (num1 && num2)
	{
		if (n == 3)
		{
			Node* p;
			p = new Node;
			p->ch = ',';
			p->next = head->next;
			head->next = p;
			n = 0;
		}
		Node* p;
		p = new Node;
		if (num1->ch == ',' && num2->ch == ',')
		{
			num1 = num1->next;
			num2 = num2->next;
			continue;
		}
		if ((int)num1->ch - (int)num2->ch - cnt >= 0)
		{
			p->ch = (char)((int)num1->ch - (int)num2->ch + 48);
			cnt = 0;
		}
		else
		{
			p->ch = (char)((int)num1->ch - (int)num2->ch - cnt + 58);
			cnt = 1;
		}
		p->next = head->next;
		head->next = p;
		n++;
	}
	while (num1)
	{
		Node* p;
		p = new Node;
		if (num1->ch == ',')
		{
			num1 = num1->next;
			continue;
		}
		if ((int)num1->ch - 48 - cnt <0)
		{
			p->ch = (char)((int)num1->ch - cnt + 10);
			cnt = 1;
		}
		else
		{
			p->ch = (char)((int)num1->ch + cnt);
			cnt = 0;
		}
		num1 = num1->next;
		p->next = head->next;
		head->next = p;
	}
	return head;
}

int main()
{
	int n;
	cin >> n;
	char addandsub;
	cin >> addandsub;
	while (n--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int len1 = s1.length(), len2 = s2.length();
		Node* num1 = NULL, * num2 = NULL;
		num1 = CreatList(num1, s1);
		num2 = CreatList(num2, s2);
		if (addandsub == '+')
		{
			if (num1->ch == '+' && num2->ch == '+')
			{
				Node* head = Add(num1, num2);
				ShowNode(head);
			}
			if (num1->ch == '-' && num2->ch == '-')
			{
				Node* head = Add(num1, num2);
				head->ch = '-';
				ShowNode(head);
			}
			if (num1->ch == '+' && num2->ch == '-')
			{
				bool big = IsBig(num1, num2);
				if (big)
				{ 
					Node* head = Sub(num1, num2);
					head->ch = '+';
					ShowNode(head);
				}
				else
				{
					Node* head = Sub(num2, num1);
					head->ch = '-';
					ShowNode(head);
				}					
			}
			if (num1->ch == '-' && num2->ch == '+')
			{
				bool big = IsBig(num1, num2);
				if (big)
				{
					Node* head = Sub(num1, num2);
					head->ch = '-';
					ShowNode(head);
				}
				else
				{
					Node* head = Sub(num2, num1);
					head->ch = '+';
					ShowNode(head);
				}
			}
		}
		else if (addandsub == '-')
		{
			if (num1->ch == '+' && num2->ch == '+')
			{
				bool big = IsBig(num1, num2);
				if (big)
				{
					Node* head = Sub(num1, num2);
					head->ch = '+';
					ShowNode(head);
				}
				else
				{
					Node* head = Sub(num2, num1);
					head->ch = '-';
					ShowNode(head);
				}
			}
			if (num1->ch == '-' && num2->ch == '-')
			{
				bool big = IsBig(num1, num2);
				if (big)
				{ 
					Node* head = Sub(num1, num2);
					head->ch = '-';
					ShowNode(head);
				}
				else
				{
					Node* head = Sub(num2, num1);
					head->ch = '+';
					ShowNode(head);
				}	
			}
			if (num1->ch == '+' && num2->ch == '-')
			{
				Node* head = Add(num1, num2);
				ShowNode(head);
			}
			if (num1->ch == '-' && num2->ch == '+')
			{
				Node* head = Add(num1, num2);
				head->ch = '-';
				ShowNode(head);
			}
		}
	}
}