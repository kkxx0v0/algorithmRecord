//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<queue>
//#include<iomanip>
//#include<algorithm>
//
//using namespace std;
//int chequer[305][305];
//int n, L;
//int beginx, beginy;
//int endx, endy;
//int jump[8][2] = {
//    -2, -1, -1, -2, -2, 1, -1, 2,
//     1, 2, 2, 1, 1, -2, 2, -1 
//};
//struct horse
//{
//    int x, y;
//    int step;
//};
//
//int main() 
//{
//    scanf("%d", &n);
//    while (n--) 
//    {
//        memset(chequer, 0, sizeof(chequer));
//        scanf("%d", &L);
//        scanf("%d%d%d%d", &beginx, &beginy, &endx, &endy);
//        if (beginx == endx && beginy == endy) 
//        {
//            printf("0\n");
//        }
//        else 
//        {
//            horse h;
//            h.x = beginx;
//            h.y = beginy;
//            h.step = 0;
//            queue<horse> q;
//            q.push(h);
//            chequer[beginx][beginy] = 1;
//            while (!q.empty())
//            {
//                horse temp = q.front();
//                q.pop();
//                for (int i = 0; i < 8; i++)
//                {
//                    h.step = temp.step + 1;
//                    h.x = temp.x + jump[i][0];
//                    h.y = temp.y + jump[i][1];
//                    if (h.x < 0 || h.x > L || h.y  < 0 || h.y > L || chequer[h.x][h.y])
//                    {
//                        continue;
//                    }
//                    if (h.x == endx && h.y == endy)
//                    {
//                        printf("%d\n", h.step);
//                    }
//                    chequer[h.x][h.y] = 1;
//                    q.push(h);
//                }
//            }
//        }
//    }
//    return 0;
//}