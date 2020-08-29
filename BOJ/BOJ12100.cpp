https://www.acmicpc.net/problem/12100
//BOJ 12100
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
 
int N, Ans;
int Map[21][21];
int BMap[5][21][21];
 
void UpAction()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N;)
        {
            int val = Map[c][r];
            int idx = -1;
            for (int c2 = c + 1; c2 < N; c2++)
            {
                if (Map[c2][r] > 0 && Map[c2][r] != val)
                {
                    break;
                }
                else if(Map[c2][r] == val)
                {
                    idx = c2;
 
                    int tmp = Map[c2][r];
                    Map[c2][r] = 0;
                    Map[c][r] *= 2;
                    break;
                }
            }
 
            if (idx == -1)
                c++;
            else
                c = idx + 1;
        }
 
        queue<int> q; 
        for (int c = 0; c < N;c++)
        {
            if (Map[c][r] > 0)
            {
                q.push(Map[c][r]);
                Map[c][r] = 0;
            }
        }
        int cidx = 0;
        while(!q.empty())
        {
            Map[cidx++][r] = q.front();
            q.pop();
        }
    }
}
 
void DownAction()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = N-1; c >=0;)
        {
            int val = Map[c][r];
            int idx = -1;
            for (int c2 = c - 1; c2 >=0; c2--)
            {
                if (Map[c2][r] > 0 && Map[c2][r] != val)
                {
                    break;
                }
                else if (Map[c2][r] == val)
                {
                    idx = c2;
 
                    int tmp = Map[c2][r];
                    Map[c2][r] = 0;
                    Map[c][r] *= 2;
                    break;
                }
            }
 
            if (idx == -1)
                c--;
            else
                c = idx - 1;
        }
 
        queue<int> q;
        for (int c = N-1; c >=0; c--)
        {
            if (Map[c][r] > 0)
            {
                q.push(Map[c][r]);
                Map[c][r] = 0;
            }
        }
        int cidx = N - 1;
        while (!q.empty())
        {
            Map[cidx--][r] = q.front();
            q.pop();
        }
    }
}
 
void LeftAction()
{
    for (int c = 0; c < N; c++)
    {
        for (int r = 0; r < N;)
        {
            int val = Map[c][r];
            int idx = -1;
            for (int r2 = r + 1; r2 < N; r2++)
            {
                if (Map[c][r2] > 0 && Map[c][r2] != val)
                {
                    break;
                }
                else if (Map[c][r2] == val)
                {
                    idx = r2;
 
                    int tmp = Map[c][r2];
                    Map[c][r2] = 0;
                    Map[c][r] *= 2;
                    break;
                }
            }
 
            if (idx == -1)
                r++;
            else
                r = idx + 1;
        }
 
        queue<int> q;
        for (int r = 0; r < N; r++)
        {
            if (Map[c][r] > 0)
            {
                q.push(Map[c][r]);
                Map[c][r] = 0;
            }
        }
        int ridx = 0;
        while (!q.empty())
        {
            Map[c][ridx++] = q.front();
            q.pop();
        }
    }
}
 
void RightAction()
{
    for (int c = 0; c < N; c++)
    {
        for (int r = N-1; r >= 0;)
        {
            int val = Map[c][r];
            int idx = -1;
            for (int r2 = r - 1; r2 >= 0; r2--)
            {
                if (Map[c][r2] > 0 && Map[c][r2] != val)
                {
                    break;
                }
                else if (Map[c][r2] == val)
                {
                    idx = r2;
 
                    int tmp = Map[c][r2];
                    Map[c][r2] = 0;
                    Map[c][r] *= 2;
                    break;
                }
            }
 
            if (idx == -1)
                r--;
            else
                r = idx - 1;
        }
 
        queue<int> q;
        for (int r = N-1; r >=0; r--)
        {
            if (Map[c][r] > 0)
            {
                q.push(Map[c][r]);
                Map[c][r] = 0;
            }
        }
        int ridx = N-1;
        while (!q.empty())
        {
            Map[c][ridx--] = q.front();
            q.pop();
        }
    }
}
 
void Backup(int l)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            BMap[l][i][j] = Map[i][j];
        }
    }
}
 
void Restore(int l)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Map[i][j] = BMap[l][i][j];
        }
    }
}
 
int FindMax()
{
    int tmpMax = 0;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmpMax = max(tmpMax, Map[i][j]);
        }
    }
 
    return tmpMax;
}
 
void Simul(int layer)
{
    Ans = max(Ans, FindMax());
 
    if (layer >= 5)
    {
        return;
    }
 
    Backup(layer);
 
    UpAction();
    Simul(layer + 1);
    Restore(layer);
 
    DownAction();
    Simul(layer + 1);
    Restore(layer);
 
    LeftAction();
    Simul(layer + 1);
    Restore(layer);
 
    RightAction();
    Simul(layer + 1);
    Restore(layer);
}
 
void SimulAll()
{
    Simul(0);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Map[i][j];
        }
    }
 
    SimulAll();
 
    cout << Ans;
 
    return 0;
}