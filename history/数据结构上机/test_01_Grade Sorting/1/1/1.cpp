#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
struct stu
{
	bool is;//是否已经输出过
	int num;
	string name;
	int chinese;
	int math;
	int english;
	int sum;
	stu()
	{
		is = 0;
		cin >> num >> name >> chinese >> math >> english;
		sum = chinese + math + english;
	}
	void print()
	{
		cout << num << " " << name << " " << sum << endl;
		is = 1;
	}
};
int main()
{
	cin >> n;
	stu* p = new stu[n];
	while (true)
	{
		//按照总成绩排序
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (!p[i].is)
			{
				if (max < p[i].sum)
				{
					max = p[i].sum;
				}
			}
		}
		vector<stu*> v;
		for (int i = 0; i < n; i++)
		{
			if (p[i].sum == max)
			{
				v.push_back(&p[i]);
			}
		}
		if (v.size()==0)
		{
			return 0;
		}
		else if (v.size() == 1)
		{
			v[0]->print();
		}
		else
		{
			//按照语文成绩排序
			while (true)
			{
				int max1 = 0;
				for (int i = 0; i < v.size(); i++)
				{
					if (!v[i]->is)
					{
						if (max1 < v[i]->chinese)
						{
							max1 = v[i]->chinese;
						}
					}
				}
				vector<stu*> tempchinese;
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i]->chinese == max1)
					{
						tempchinese.push_back(v[i]);
					}
				}
				if (tempchinese.size() == 0)
				{
					break;
				}
				else if (tempchinese.size() == 1)
				{
					tempchinese[0]->print();
				}
				else
				{
					//按照数学成绩排序
					while (true)
					{
						int max2 = 0;
						for (int i = 0; i < tempchinese.size(); i++)
						{
							if (!tempchinese[i]->is)
							{
								if (max2 < tempchinese[i]->math)
								{
									max2 = tempchinese[i]->math;
								}
							}
						}
						vector<stu*> tempmath;
						for (int i = 0; i < tempchinese.size(); i++)
						{
							if (tempchinese[i]->math == max2)
							{
								tempmath.push_back(tempchinese[i]);
							}
						}
						if (tempmath.size() == 0)
						{
							break;
						}
						else if (tempmath.size() == 1)
						{
							tempmath[0]->print();
						}
						else
						{
							//按照学号排序
							while (true)
							{
								int min = -1;
								int i = 0;
								for (; i < tempmath.size(); i++)
								{
									if (!tempmath[i]->is)
									{
										if (tempmath[min]->math < tempmath[i]->math)
										{
											min = i;
										}
									}
								}
								if (min == -1)
								{
									break;
								}
								else
									tempmath[i]->print();
							}
						}
					}
				}
			}
		}
	}
}