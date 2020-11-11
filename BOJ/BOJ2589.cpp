//https://www.acmicpc.net/problem/2589

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


typedef pair<int, int> pii;
typedef pair<int, pii> pippi;

char Map[51][51];
int visit[51][51];
int dc[4] = { 1, -1, 0, 0 };
int dr[4] = { 0, 0, 1, -1 };
int Col, Row;
int Ans;

bool isPromising(int nextCol, int nextRow, int nextCnt)
{
    bool isprom = false;

    if (visit[nextCol][nextRow] == 0 || (nextCnt < visit[nextCol][nextRow] && visit[nextCol][nextRow] != 0))
    {
        if (nextCol < Col && nextCol >= 0 && nextRow >= 0 && nextRow < Row)
        {
            isprom = true;
        }
    }

    return isprom;
}

void bfs(int sc,int sr)
{
    queue<pippi> q;
    q.push({ 1, { sc, sr } });

    while (!q.empty())
    {
        int curCol = q.front().second.first;
        int curRow = q.front().second.second;
        int curCnt = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextCol = curCol + dc[i];
            int nextRow = curRow + dr[i];
            int nextCnt = curCnt + 1;
            char nextStat = Map[nextCol][nextRow];

            if (nextStat == 'W')
            {
                continue;
            }

            if (isPromising(nextCol, nextRow, nextCnt))
            {
                Ans = max(nextCnt, Ans);
                visit[nextCol][nextRow] = nextCnt;
                q.push({ nextCnt, { nextCol, nextRow } });
            }
        }
    }
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> Col >> Row;

    int c;
    for (int i = 0; i < Col; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < Row; j++)
        {
            Map[i][j] = str[j];
        }
    }

    for (int i = 0; i < Col; i++)
    {
        for (int j = 0; j < Row; j++)
        {
            if (Map[i][j] == 'L')
            {
                memset(visit, 0, sizeof(visit));
                visit[i][j] = 1;
                bfs(i, j);
            }
        }
    }

    cout << Ans - 1;

    return 0;
}

