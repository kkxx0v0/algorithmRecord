#include<iostream>
#include <iomanip>
using namespace std;
class RMB
{
public:
	int yuan;
	int jiao;
	int fen;
	bool mark;
	RMB()
	{
		yuan = 0;
		jiao = 0;
		fen=0;
		mark = true;
	}
	RMB(int yuan,int jiao,int fen)
	{
		this->yuan = yuan;
		this->jiao = jiao;
		this->fen = fen;
		mark = true;
	}
	RMB(double num)
	{
		this->yuan = (int)num;
		this->jiao = (int)(num*10-(double)yuan*10);
		this->fen = (int)(num * 100 - (double)yuan * 100 - (double)jiao * 10);
		mark = true;
	}
	bool IsBig(const RMB& b)
	{
		double value1 = 0.0f, value2 = 0.0f;
		value1 = this->yuan + this->jiao * 0.1 + this->fen * 0.01;
		value2 = b.yuan + b.jiao * 0.1 + b.fen * 0.01;
		if (value1 >= value2)
			return true;
		return false;
	}
	RMB operator-(RMB& b)
	{
		RMB a(yuan, jiao, fen);
		RMB temp2(yuan, jiao, fen);
		if (a.IsBig(b))
		{
			if (a.fen - b.fen<0)
			{
				a.jiao -= 1;
				a.fen += 10;
			}
			temp2.fen = a.fen - b.fen;
			if (a.jiao - b.jiao < 0)
			{
				a.yuan -= 1;
				a.jiao += 10;
			}
			temp2.yuan = a.yuan - b.yuan;
			temp2.jiao = a.jiao - b.jiao;
		}
		else
		{
			if (b.fen-a.fen   < 0)
			{
				b.jiao -= 1;
				b.fen += 10;
			}
			temp2.fen =  b.fen-a.fen ;
			if ( b.jiao -a.jiao < 0)
			{
				a.yuan -= 1;
				a.jiao += 10;
			}
			temp2.yuan =   b.yuan-a.yuan;
			temp2.jiao = b.jiao -a.jiao ;
			temp.mark=false;
		}
		return temp2;
	}
	friend istream& operator>>(istream&, const RMB&);
	friend ostream& operator<<(ostream&, const RMB&);
};
istream& operator>>(istream& input, RMB& R)
{
	input >> R.yuan;
	input >> R.jiao;
	input >> R.fen;
	R.mark = true;
	return input;
}
ostream& operator<<(ostream& output, const RMB& R)
{
	double value = 0;
	value = (double)R.yuan + (double)R.jiao * 0.1 + (double)R.fen * 0.01;
	if (!R.mark)
	{
		cout << '-';
	}
	output << value;
	return output;
}
RMB operator+(const RMB& a, const RMB& b)
{
	RMB temp;
	temp.yuan = a.yuan + b.yuan;
	temp.jiao = a.jiao + b.jiao;
	temp.fen = a.fen + b.fen;
	if (temp.fen >= 10)
	{
		temp.fen -= 10;
		temp.jiao++;
		if (temp.jiao >= 10)
		{
			temp.jiao -= 10;
			temp.yuan++;
		}
	}
	return temp;
}
int main()
{
	RMB a, b;
	double c;
	cout.setf(cout.showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	cin >> a;
	cin >> b;
	cin >> c;
	cout << RMB(a + c) << endl;
	cout << RMB(b - a) << endl;
	cout << RMB(2.18 + a) << endl;
	return 0;
}