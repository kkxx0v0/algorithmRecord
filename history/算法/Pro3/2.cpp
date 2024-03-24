#include<iostream>
#include<map>
using namespace std;
int c[110000]{};
int f[110000]{};
int max(int x, int y)
{
	return x > y ? x : y;
}
//int main()
//{
//	int n, m, sum = 0;
//	cin >> n >> m;
//	map<int, int> card;
//	for (int i = 0; i < n; i++)
//	{
//		char ch;
//		cin >> ch;
//		switch (ch)
//		{
//		case 'A':
//			c[i] = 1;
//			card[1]++;
//			sum += c[i];
//			break;
//		case '2':
//			c[i] = 2;
//			card[2]++;
//			sum += c[i];
//			break;
//		case '3':
//			c[i] = 3;
//			card[3]++;
//			sum += c[i];
//			break;
//		case '4':
//			c[i] = 4;
//			card[4]++;
//			sum += c[i];
//			break;
//		case '5':
//			c[i] = 5;
//			card[5]++;
//			sum += c[i];
//			break;
//		case '6':
//			c[i] = 6;
//			card[6]++;
//			sum += c[i];
//			break;
//		case '7':
//			c[i] = 7;
//			card[7]++;
//			sum += c[i];
//			break;
//		case '8':
//			c[i] = 8;
//			card[8]++;
//			sum += c[i];
//			break;
//		case '9':
//			c[i] = 9;
//			card[9]++;
//			sum += c[i];
//			break;
//		case '10':
//			c[i] = 10;
//			card[10]++;
//			sum += c[i];
//			break;
//		case 'J':
//			c[i] = 11;
//			card[11]++;
//			sum += c[i];
//			break;
//		case 'Q':
//			c[i] = 12;
//			card[12]++;
//			sum += c[i];
//			break;
//		case 'K':
//			c[i] = 13;
//			card[13]++;
//			sum += c[i];
//			break;
//		default:
//			break;
//		}
//	}
//
//	if (sum < m)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	else if (sum == m)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	int num = m;
//	while (num > 0)
//	{
//		int tmp = -1;
//		for (auto it : card)
//		{
//			if (it.first < num)
//			{
//				tmp = it.first;
//			}
//			else
//				break;
//		}
//		if (tmp < 0)
//		{
//			for (auto it : card)
//			{
//				if (it.first > m)
//				{
//					cout << sum - it.first << endl;
//					return 0;
//				}
//			}
//		}
//		num -= tmp;
//	}
//}

bool card[1001000];
int main()
{
    int n, m;
    cin >> n >> m;
    card[0] = true;
    int sum = 0;
    while (n-- > 0) 
    {
        char v[3];
        cin >> v;
        int val = v[0] == 'A' ? 1
                : v[0] == 'J' ? 11
                : v[0] == 'Q' ? 12
                : v[0] == 'K' ? 13
                : std::atoi(v);
        sum += val;
        for (int i = m + 12; i >= val; --i)
        {
            card[i] |= card[i - val];
        }
    }
    for (int i = m; i <= m + 12; ++i)
    {
        if (card[i])
        {
            cout << sum - i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}