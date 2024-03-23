﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int sx, sy;
int fx, fy;
int mapx, mapy;
int visited[501][501];
int dir[8][2] = { {-2,-1},{-1,-2},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };
struct Node
{
    int x;
    int y;
    Node(int x, int y) :x(x), y(y) {}
};
int bfs()
{
    if (sx == fx && sy == fy)
        return 0;
    queue<Node> q;
    Node s = Node(sx, sy);
    q.push(s);
    visited[sx][sy] = 0;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        int step = visited[s.x][s.y] + 1;
        for (int i = 0; i < 8; i++)
        {
            int nx = s.x + dir[i][0];
            int ny = s.y + dir[i][1];
            if (!visited[nx][ny] && nx > 0 && nx <= mapx && ny > 0 && ny <= mapy)
            {
                if (nx == fx && ny == fy)
                {
                    visited[nx][ny] = step;
                    return step;
                }  
                q.push(Node(nx, ny));
                visited[nx][ny] = step;
            }
        }
    }
}
int main()
{
    //freopen("马踏棋盘test.in", "r", stdin);
    //freopen("马踏棋盘test.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> mapx >> mapy;
        memset(visited, 0, sizeof(visited));
        cin >> sx >> sy;
        cin >> fx >> fy;
        cout << bfs() << endl;
    }
    return 0;
}