#include<iostream>
using namespace std;
char op[4] = { '+','-','*','/' };
float calculate(float x, float y, int op)
{
	switch (op) 
	{
	case 0:
		return x + y;
		break;
	case 1:
		return x - y;
		break;
	case 2:
		return x * y;
		break;
	case 3:
		if (y != 0)
			return x / y;
		break;
	}
	return 0;
}
float cal1(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(a, b, op1);
	t2 = calculate(t1, c, op2);
	return calculate(t2, d, op3);
}
float cal2(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(b, c, op2);
	t2 = calculate(a, t1, op1);
	return calculate(t2, d, op3);
}
float cal3(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(c, d, op3);  
	t2 = calculate(b, t1, op2);
	return calculate(a, t2, op1);
}
float cal4(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(b, c, op2); 
	t2 = calculate(t1, d, op3);
	return calculate(a, t2, op1);
}
float cal5(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(a, b, op1);
	t2 = calculate(c, d, op3);
	return calculate(t1, t2, op2);
}
float cal6(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float t1, t2;
	t1 = calculate(a, d, op1);
	t2 = calculate(b, t1, op3);
	return calculate(c, t2, op2);
}
int get24(float a, float b, float c, float d)
{
	int op1, op2, op3;
	for (op1 = 0; op1 < 4; op1++)
	{
		for (op2 = 0; op2 < 4; op2++)
		{
			for (op3 = 0; op3 < 4; op3++)
			{
				if (cal1(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
				if (cal2(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
				if (cal3(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
				if (cal4(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
				if (cal5(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
				if (cal6(a, b, c, d, op1, op2, op3) == 24)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		if (get24(a, b, c, d))
			cout << "YES"<<endl;
		else
			cout << "NOT"<<endl;
	}
}