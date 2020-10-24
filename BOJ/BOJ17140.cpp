https://www.acmicpc.net/problem/17140
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
int r, c, k;
int Ans, Col, Row;
int NumCnt[101];
int A[100][100];
 
void SolveR()
{
    int tmprow=0;
    vector<pair<int, int> > v;
 
    for (int i = 0; i < Col; i++)
    {
        v.clear();
        memset(NumCnt, 0, sizeof(NumCnt));
 
        for (int j = 0; j < Row; j++)
        {
            if (A[i][j] > 0)
            {
                NumCnt[A[i][j]] += 1;
            }
        }
 
        for (int j = 1; j <= 100; j++)
        {
            if (NumCnt[j] > 0)
            {
                v.push_back({ NumCnt[j],j });
            }
        }
 
        for (int j = 0; j < Row; j++)
        {
            A[i][j] = 0;
        }
 
        sort(v.begin(), v.end());
 
        int tmpidx = 0;
 
        for (int k = 0; k < v.size(); k++)
        {
            A[i][tmpidx] = v[k].second;
            tmpidx += 1;
            if (tmpidx == 100)
            {
                break;
            }
            A[i][tmpidx] = v[k].first;
            tmpidx += 1; 
            if (tmpidx == 100)
            {
                break;
            }
 
            tmprow = max(tmprow, tmpidx);
        }
    }
 
    Row = max(Row, tmprow);
}
 
void SolveC()
{
    int tmpcol=0;
    vector<pair<int, int> > v;
 
    for (int j = 0; j < Row; j++)
    {
        v.clear();
        memset(NumCnt, 0, sizeof(NumCnt));
 
        for (int i = 0; i < Col; i++)
        {
            if (A[i][j] > 0)
            {
                NumCnt[A[i][j]] += 1;
            }
        }
 
        for (int j = 1; j <= 100; j++)
        {
            if (NumCnt[j] > 0)
            {
                v.push_back({ NumCnt[j],j });
            }
        }
 
        for (int i = 0; i < Col; i++)
        {
            A[i][j] = 0;
        }
 
        sort(v.begin(), v.end());
 
        int tmpidx = 0;
 
        for (int k = 0; k < v.size(); k++)
        {
            A[tmpidx][j] = v[k].second;
            tmpidx += 1;
            if (tmpidx == 100)
            {
                break;
            }
            A[tmpidx][j] = v[k].first;
            tmpidx += 1;
            if (tmpidx == 100)
            {
                break;
            }
 
            tmpcol = max(tmpcol, tmpidx);
        }
    }
 
    Col = max(Col, tmpcol);
}
 
void SolveAll()
{
    if (A[r - 1][c - 1] == k)
    {
        Ans = 0;
        return;
    }
 
    Col = 3;
    Row = 3;
 
    int cnt = 1;
    while (1)
    {
        memset(NumCnt, 0, sizeof(NumCnt));
        if (cnt > 100)
        {
            Ans = -1;
            break;
        }
 
        if (Col >= Row)
        {
            SolveR();
        }
        else
        {
            SolveC();
        }
 
        if (A[r - 1][c - 1] == k)
        {
            Ans = cnt;
            return;
        }
 
        cnt += 1;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
 
    cin >> r >> c >> k;
 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }
 
    SolveAll();
 
    cout << Ans;
 
    return 0;
}