#include<iostream>
using namespace std;
class Student
{
public:
	int score;
	static int total;
	static int count;
	void scoretotalcount(int s)
	{
		score = s;
		total += s;
		count++;
	}
	static void sum()
	{	
		cout<< total << " ";
	}
	static void average()
	{
		cout << total / count << endl;
	}
};
int Student::total = 0;
int Student::count = 0;
int main()
{
	Student S[5];
	for (int i = 0; i < 5; i++)
	{
		int s;
		cin >> s;
		S[i].scoretotalcount(s);
	}
	S->sum();
	S->average();
}