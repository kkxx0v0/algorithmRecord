#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

//链表结点结构体
struct Node
{
	int data;//数据域——由于只保存数字选int
	Node* next;//指针域
};

//返回绝对值
int Abs(int num)
{
	if (num >= 0)
	{
		return num;
	}
	else
		return -num;
}

//创建链表函数
//参数：头指针，当前位置指针，要存入的单个数字
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

//输出链表
//参数——头指针，小数位数
string ShowList(Node* head, int num)
{
	string list="";
	num -= 1;
	//打印小数部分
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
		list += to_string(head->data);//int转string才能使用+
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

//加法函数
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

//减法函数
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

//判断大小函数
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

//删除正负号，逗号和小数点函数
//参数：要处理的字符串和正负代表变量
//返回整数位
int Delete(string& num, bool& neg)
{
	int i = 0;
	if (num[0] == '-')//删除负号
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
		else if (num[i] == '.')//找到小数点则确定小数位
		{
			length = num.length() - i;
		}
		else
			tmp += num[i];
	}
	num = tmp;
	return length;
}

//主函数
int main()
{
	int n;
	cin >> n;
	string num1, num2, type;//type为符号
	while (n--)
	{
		cin >> type >> num1 >> num2;
		bool neg1 = true, neg2 = true;//分别表示num1,num2正负情况
		Node* head1 = NULL, *head2 = NULL, * p;
		int length1 = Delete(num1, neg1), length2 = Delete(num2, neg2);//删除符号并记录小数位
		int num3 = Abs(length1 - length2);//小数位差值
		int num4 = length1 > length2 ? length1 : length2;//小数位最大值

		//小数位少的补0
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

		//分别将num1,num2变为链表
		//倒叙存入
		for (int i = num1.length(); i > 0; i--)
		{
			CreateList(head1, p, (int)num1[i - 1] -48);
		}
		for (int i = num2.length(); i > 0; i--)
		{
			CreateList(head2, p, (int)num2[i - 1] - 48);
		}

		//neg3保存
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