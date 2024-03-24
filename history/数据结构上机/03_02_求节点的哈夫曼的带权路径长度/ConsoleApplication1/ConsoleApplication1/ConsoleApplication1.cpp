#include<iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;

struct HTNode{
	int weight;
	int parent, left, right;
    HTNode()
    {
        parent = left = right = weight = 0;
    }
};

void Select(HTNode* HT, int end, int* s1, int* s2)
{
    int min1, min2;
    int i = 1;
    while (HT[i].parent != 0 && i <= end) {
        i++;
    }
    min1 = HT[i].weight;
    *s1 = i;
    i++;
    while (HT[i].parent != 0 && i <= end) {
        i++;
    }
    if (HT[i].weight < min1) {
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    }
    else {
        min2 = HT[i].weight;
        *s2 = i;
    }
    for (int j = i + 1; j <= end; j++)
    {
        if (HT[j].parent != 0) {
            continue;
        }
        if (HT[j].weight < min1) {
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }
        else if (HT[j].weight >= min1 && HT[j].weight < min2) {
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}

void CreateHuffmanTree(HTNode* HT, int* p, int n)
{
    int m = 2 * n - 1;
    for (int i = 1; i <= n; i++)
    {
        HT[i].weight = p[i-1];
        HT[i].parent = 0;
        HT[i].left = 0;
        HT[i].right = 0;
    }
    for (int i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, &s1, &s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].left = s1;
        HT[i].right = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
int main()
{
    priority_queue <  int, vector<int>, greater<int >> q;
    int T,num;
    cin >> T;
    while (T--)
    {
        cin >> num;
        q.push(num);
    }
    int ans = 0;
    while (q.size()>=2)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans += (a + b);
    }
    cout << ans <<endl;
    /*int* p = new int[2 * vec.size()];
    for (int i = 1; i <= vec.size(); i++)
    {
        p[i] = vec[i - 1];
    }
    HTNode* HT = new HTNode[2 * vec.size()];
    CreateHuffmanTree(HT, p, vec.size());
    cout<<HT*/
}