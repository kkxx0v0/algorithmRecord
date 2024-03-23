#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int data;
    node* link;
    node()
    {
        link = NULL;
    }
};

int maxnum;

node* CreatList()
{
    node* head = new node;
    node* p = head;
    int c;
    maxnum = 0;
    while (cin >> c)
    {
        node* q = new node;
        if (c > maxnum)
        {
            maxnum = c;
        }
        q->data = c;
        p->link = q;
        p = p->link;
    }
    return head;
}

node* Deal(node* head)
{
    node* temp = head ,*p = NULL;
    while (temp)
    {
        if (temp->data == maxnum)
        {
            p = temp;
            break;
        }
        temp = temp->link;
    }
    temp = head;
    while (temp->link != p)
    {
        temp = temp->link;
    }
    if (p->link == NULL)
    {
        return head;
    }
    else
    {
        temp->link = p->link;
        p->link = NULL;
        while (temp->link)
        {
            temp = temp->link;
        }
        temp->link = p;
    }
    return head;
}

void ShowList(node* head)
{
    head = head->link;
    while (head)
    {
        cout << head->data << " ";
        head = head->link;
    }
}

int main()
{
    node* head = CreatList();
    Deal(head);
    ShowList(head);
}