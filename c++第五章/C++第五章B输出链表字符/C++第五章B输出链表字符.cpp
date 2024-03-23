#include <iostream>
#include <string>
using namespace std;
struct Str
{
	string s;
	Str* next;
};
Str* CreateList(int n, string s)
{
	Str* head = new Str;
	Str* pre = head;
	for (int i = n - 1; i >= 0; i--)
	{
		Str* p = new Str;
		p->s = s[i];
		pre->next = p;
		pre = p; 
		p->next = NULL; 
	}
	return head;
}
void display(Str* head)
{
	while (head->next != NULL)
	{
		cout << head->next->s;
		head->next = head->next->next;
	}
	cout << endl;
}
int main()
{
	int i = 3;
	while (i--)
	{
		int n;
		string s;
		cin >> s;
		n = s.length();
		Str* head = CreateList(n, s);
		display(head);
	}
}