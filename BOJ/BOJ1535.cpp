//BOJ 1535
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 
int N, Ans;
int L[20];
int J[20];
 
void SimulDFS(int idx,int life,int happy)
{
    if (life <= 0)
        return;
 
    if (idx == N)
    {
        Ans = max(happy, Ans);
        return;
    }
 
    SimulDFS(idx + 1, life - L[idx], happy + J[idx]);
    SimulDFS(idx + 1, life, happy);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int Life, Happy;
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
 
    for (int i = 0; i < N; i++)
    {
        cin >> J[i];
    }
 
    Life = 100;
    Happy = 0;
 
    SimulDFS(1, Life - L[0], Happy + J[0]);
    SimulDFS(1, Life, Happy);
 
    cout << Ans;
 
    return 0;
}
