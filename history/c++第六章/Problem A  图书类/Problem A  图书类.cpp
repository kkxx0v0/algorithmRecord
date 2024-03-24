#include<iostream>
#include<string>
using namespace std;
class Book
{
public:
	string bookname;
	int price;
	int number;
	void display();
	void borrow();
	void restore();
};
void Book::display()
{
	cout << bookname << " " << price << " " << number << endl;
	return;
}
void Book::borrow()
{
	number--;
	cout << number << endl;
	return;
}
void Book::restore()
{
	number++;
	cout << number << endl;
	return;
}
int main()
{
	Book MyBook;
	cin >> MyBook.bookname >> MyBook.price >> MyBook.number;
	MyBook.display();
	int t = 5;
	char ch;
	while (t--)
	{
		cin >> ch;
		switch (ch)
		{
		case 'B':
			MyBook.borrow();
			break;
		case 'R':
			MyBook.restore();
			break;
		case 'C':
			cout << MyBook.price * MyBook.number << endl;
			break;
		default:
			break;
		}
	}
}