#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

//������ṹ��
struct Node
{
	int data;//�����򡪡�����ֻ��������ѡint
	Node* next;//ָ����
};

//���ؾ���ֵ
int Abs(int num)
{
	if (num >= 0)
	{
		return num;
	}
	else
		return -num;
}

//����������
//������ͷָ�룬��ǰλ��ָ�룬Ҫ����ĵ�������
void CreateList(Node*& head, Node*& p, int num)
{
	Node* s;
	s = new Node;
	s->data = num;
	s->next = NULL;
	if (head == NULL)
	{
		head = s;
		p = s;
	}
	else
		p->next = s;
	p = s;
}

//�������
//��������ͷָ�룬С��λ��
string ShowList(Node* head, int num)
{
	string list="";
	num -= 1;
	//��ӡС������
	if (num > 0)
	{
		for (int i=num; i > 0; i--)
		{
			list += to_string(head->data);
			head = head->next;
		}
		list += ".";
	}
	int point = 0;
	while (head)
	{
		list += to_string(head->data);//intתstring����ʹ��+
		head = head->next;
		point++;
		if (!(point % 3))
		{
			list += ",";
		}
	}
	if (!(point % 3))
	{
		string s(list, 0, list.length() - 1);
		list = s;
	}
	reverse(list.begin(), list.end());
	bool Delete = true;
	while (Delete)
	{
		if (list[0] == '0' && list[1] == '.')
		{
			Delete = false;
		}
		else if (list[0] == '0' || list[0] == ',')
		{
			string s(list, 1, list.length());
			list = s;
		}
		else
			Delete = false;
	}
	if (list[0] == NULL)
	{
		list += "0";
	}
	Delete = true;
	while (Delete)
	{
		bool ifpoint = false;
		if (num>0)
		{
			ifpoint = true;
		}		
		if (ifpoint)
		{
			if (list[list.length() - 1] == '0')
			{
				string s(list, 0, list.length() - 1);
				list = s;
			}
			else if (list[list.length() - 1] == '.')
			{
				string s(list, 0, list.length() - 1);
				list = s;
				Delete = false;
			}
			else
				Delete = false;
		}
		else
			Delete = false;
	}
	return list;
}

//�ӷ�����
Node* add(Node* head1, Node* head2)
{
	int cnt = 0;
	Node* head = NULL, * p;
	while (head1 && head2)
	{
		int data = head1->data + head2->data + cnt;
		if (data >= 10)
		{
			data -= 10;
			cnt = 1;
		}
		else
			cnt = 0;
		CreateList(head, p, data);
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 || head2)
	{
		int data = (head1 == NULL ? head2->data : head1->data) + cnt;
		if (data >= 10)
		{
			data -= 10;
			cnt = 1;
		}
		else
			cnt = 0;
		CreateList(head, p, data);
		(head1 == NULL ? head2 : head1) = (head1 == NULL ? head2 : head1)->next;
	}
	if (cnt)
	{
		CreateList(head, p, 1);
	}
	return head;
}

//��������
Node* Subtract(Node* head1, Node* head2)
{
	int cnt = 0;
	Node* head = NULL, * p;
	while (head1 && head2)
	{
		int data = (head1->data - head2->data - cnt);
		if (data < 0)
		{
			data += 10;
			cnt = 1;
		}
		else
			cnt = 0;
		CreateList(head, p, data);
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 || head2)
	{
		int data = (head1 == NULL ? head2->data : head1->data) - cnt;
		if (data < 0)
		{
			data += 10;
			cnt = 1;
		}
		else
			cnt = 0;
		CreateList(head, p, data);
		(head1 == NULL ? head2 : head1) = (head1 == NULL ? head2 : head1)->next;
	}
	return head;
}

//�жϴ�С����
bool judge(string num1, string num2)
{
	bool neg3 = num1.length() > num2.length() ? true : false;
	if (neg3 == false)
	{
		int equal = 1, i = 0;
		while (equal)
		{
			if (num1[i] > num2[i])
			{
				neg3 = true;
				equal = 0;
			}
			else if (num1[i] == num2[i])
			{
				if (i == num1.length() - 1)
				{
					equal = 0;
				}
				else
				{
					i++;
				}
			}
			else
			{
				equal = 0;
			}
		}
	}
	return neg3;
}

//ɾ�������ţ����ź�С���㺯��
//������Ҫ������ַ����������������
//��������λ
int Delete(string& num, bool& neg)
{
	int i = 0;
	if (num[0] == '-')//ɾ������
	{
		neg = false;
		++i;
	}
	int length = 0;
	string tmp = "";	
	for (; i <num.length(); ++i)
	{
		if (num[i] == ',')
		{
			continue;
		}
		else if (num[i] == '.')//�ҵ�С������ȷ��С��λ
		{
			length = num.length() - i;
		}
		else
			tmp += num[i];
	}
	num = tmp;
	return length;
}

//������
int main()
{
	int n;
	cin >> n;
	string num1, num2, type;//typeΪ����
	while (n--)
	{
		cin >> type >> num1 >> num2;
		bool neg1 = true, neg2 = true;//�ֱ��ʾnum1,num2�������
		Node* head1 = NULL, *head2 = NULL, * p;
		int length1 = Delete(num1, neg1), length2 = Delete(num2, neg2);//ɾ�����Ų���¼С��λ
		int num3 = Abs(length1 - length2);//С��λ��ֵ
		int num4 = length1 > length2 ? length1 : length2;//С��λ���ֵ

		//С��λ�ٵĲ�0
		if (length1 > length2)
		{
			for (int i = num3; i > 0; i--)
			{
				num2 += "0";
			}
		}
		else
		{
			for (int i = num3; i > 0; i--)
			{
				num1 += "0";
			}
		}

		//�ֱ�num1,num2��Ϊ����
		//�������
		for (int i = num1.length(); i > 0; i--)
		{
			CreateList(head1, p, (int)num1[i - 1] -48);
		}
		for (int i = num2.length(); i > 0; i--)
		{
			CreateList(head2, p, (int)num2[i - 1] - 48);
		}

		//neg3����
		bool neg3 = judge(num1, num2);

		if (neg1 == neg2)
		{
			if (type == "+")
			{
				if (neg1 == true)
					cout << ShowList(add(head1, head2), num4);
				else
				{
					if (ShowList(add(head1, head2), num4) != "0")
						cout << "-";
					cout << ShowList(add(head1, head2), num4);
				}
			}
			if (type == "-")
			{
				if (neg3 == true)
				{
					if (neg1 == false && ShowList(Subtract(head1, head2), num4) != "0")
						cout << "-";
					cout << ShowList(Subtract(head1, head2), num4);
				}
				else
				{
					if (neg1 == true && ShowList(Subtract(head1, head2), num4) != "0")
					{
						cout << "-";
					}
					cout << ShowList(Subtract(head2, head1), num4);
				}
			}
		}
		else if (neg1 != neg2)
		{
			if (type == "+")
			{
				if (neg3 == true)
				{
					if (neg1 != true && ShowList(Subtract(head1, head2), num4) != "0")
						cout << "-";
					cout << ShowList(Subtract(head1, head2), num4);
				}
				else
				{
					if (neg2 != true && ShowList(Subtract(head1, head2), num4) != "0")
						cout << "-";
					cout << ShowList(Subtract(head2, head1), num4);
				}
			}
			else
			{
				if (neg1 != true && ShowList(add(head1, head2), num4) != "0")
					cout << "-";
				if (neg3 == true)
				{
					cout << ShowList(add(head1, head2), num4);
				}
				else
				{
					cout << ShowList(add(head2, head1), num4);
				}
			}
		}
		cout << endl;
	}
}