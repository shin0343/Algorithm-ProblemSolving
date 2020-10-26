//https://www.acmicpc.net/problem/15685
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
 
 
typedef struct _DC
{
    int col;
    int row;
    int dir;
    int gen;
}DC;
 
int dc[4] = { 0,-1,0,1 };
int dr[4] = { 1,0,-1,0 };
int N, Ans;
vector<DC> DCs;
bool Visit[101][101];
 
void FindAns()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (Visit[i][j] && Visit[i+1][j+1] && Visit[i+1][j] && Visit[i][j+1])
            {
                Ans += 1;
            }
        }
    }
}
 
void Solve(int dci)
{
    vector<int> dirdragon;
 
 
    int c = DCs[dci].col;
    int r = DCs[dci].row;
    int d = DCs[dci].dir;
    int g = DCs[dci].gen;
    Visit[c][r] = true;
 
    c = c + dc[d];
    r = r + dr[d];
    Visit[c][r] = true;
    dirdragon.push_back(d);
 
    for (int i = 1; i <= g; i++)
    {
        int dsize = dirdragon.size();
 
        for (int i = dsize - 1; i >= 0; i--)
        {
            int d = (dirdragon[i] + 1) % 4;
 
            c = c + dc[d];
            r = r + dr[d];
 
            Visit[c][r] = true;
 
            dirdragon.push_back(d);
        }
    }
}
 
void SolveAll()
{
    for (unsigned int i = 0; i < DCs.size(); i++)
    {
        Solve(i);
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        DC dc;
        cin >> dc.row >> dc.col >> dc.dir >> dc.gen;
 
        DCs.push_back(dc);
    }
 
    SolveAll();
    FindAns();
 
    cout << Ans;
 
    return 0;
}