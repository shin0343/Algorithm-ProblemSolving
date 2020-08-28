https://www.acmicpc.net/problem/3190
//BOJ 3190
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
 
#define UP 0 
#define RIGHT 1
#define DOWN 2 
#define LEFT 3
 
#define SNK 10
#define FRT 20
 
struct SNAKE
{
    int dir;
    int len;
};
 
int N, K, L, Ans;
int ExitFlag = 0;
int dc[] = { -1,0,1,0 };
int dr[] = { 0,1,0,-1 };
int Map[101][101]; //1~100행, 1~100열
SNAKE Snake;
vector<pair<int, char> > Dirs;
queue<pair<int, int> > q;
 
//void PrintMap()
//{
//    cout << endl;
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= N; j++)
//        {
//            printf("%2d ", Map[i][j]);
//        }
//        cout << endl;
//    }
//}
 
void Simul()
{
    int nc, nr;
    nc = q.back().first + dc[Snake.dir];
    nr = q.back().second + dr[Snake.dir];
 
    if (nc <= 0 || nr <= 0 || nc > N || nr > N)
    {
        ExitFlag = 1;
        return;
    }
 
    if (Map[nc][nr] == SNK)
    {
        ExitFlag = 1;
        return;
    }
 
    q.push({ nc,nr });
    if (Map[nc][nr] != FRT)
    {
        Map[q.front().first][q.front().second] = 0;
        q.pop();
    }
    else
    {
        Snake.len += 1;
    }
    Map[nc][nr] = SNK;
}
 
void SimulAll()
{
    Snake.len = 1;
    Snake.dir = RIGHT;
    q.push({ 1,1 });
    Map[1][1] = SNK;
 
 
    int dirIdx = 0;
    int sec;
    for (sec = 1; sec <= N * N; sec++)
    {
        Simul();
 
        if (ExitFlag)
        {
            break;
        }
 
        if (dirIdx < L && Dirs[dirIdx].first == sec)
        {
            if (Dirs[dirIdx].second == 'L')
            {
                Snake.dir -= 1;
                if (Snake.dir < 0)
                    Snake.dir = 3;
            }
            else if (Dirs[dirIdx].second == 'D')
            {
                Snake.dir += 1;
                if (Snake.dir > 3)
                    Snake.dir = 0;
            }
 
            dirIdx += 1;
        }
    }
 
    Ans = sec;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
 
    cin >> N >> K;
 
    int c, r;
    for (int i = 0; i < K; i++)
    {
        cin >> c >> r;
 
        Map[c][r] = FRT;
    }
 
    cin >> L;
 
    int sec;
    char rot;
    for (int i = 0; i < L; i++)
    {
        cin >> sec >> rot;
        Dirs.push_back({ sec,rot });
    }
 
    SimulAll();
 
    cout << Ans;
 
    return 0;
}
