https://www.acmicpc.net/problem/16234

//BOJ 16234
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
 
bool Visit[51][51];
int A[51][51];
int BackupA[51][51];
int dc[] = { 1,-1,0,0 };
int dr[] = { 0,0,1,-1 };
int N, L, R;
int Ans;
int ChangeFlag;
vector<pair<int, int> > v;
 
bool IsPromsing(int c, int r)
{
    if (c >= 0 && r >= 0 && c < N && r < N 
        && Visit[c][r] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
void SimulBFS(int c,int r)
{
    queue<pair<int, int> > q;
 
    Visit[c][r] = true;
    v.push_back({ c,r });
    q.push({ c,r });
 
    while (!q.empty())
    {
        int cc = q.front().first;
        int cr = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nc = cc + dc[i];
            int nr = cr + dr[i];
 
            if (IsPromsing(nc, nr))
            {
                if (abs(A[cc][cr] - A[nc][nr]) >= L 
                    && abs(A[cc][cr] - A[nc][nr]) <= R)
                {
                    Visit[nc][nr] = true;
                    v.push_back({ nc,nr });
                    q.push({ nc,nr });
                }
            }
        }
    }
 
    int sum = 0;
    int vSize = v.size();
    if (vSize > 1)
    {
        ChangeFlag = 1;
    }
    for (int i = 0; i < vSize; i++)
    {
        sum += A[v[i].first][v[i].second];
    }
    
    sum /= vSize;
 
    for (int i = 0; i < vSize; i++)
    {
        A[v[i].first][v[i].second] = sum;
    }
}
 
void SimulAll()
{
    for (int i = 0; i < 2000; i++)
    {
        ChangeFlag = 0;
        memset(Visit, 0, sizeof(Visit));
 
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (Visit[j][k] == false)
                {
                    v.clear();
                    SimulBFS(j, k);
                }
            }
        }
 
        if (ChangeFlag==0)
        {
            return;
        }
        else
        {
            Ans += 1;
            ChangeFlag = 0;
            continue;
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
 
    cin >> N >> L >> R;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;
 
            A[i][j] = input;
        }
    }
 
    SimulAll();
 
    cout << Ans;
 
    return 0;
}