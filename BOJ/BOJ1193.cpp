//https://www.acmicpc.net/problem/1193
#include <iostream>
using namespace std;
 
 
int X, l, r;
 
void solve()   
{
    int cnt = 0;
    int lrSum = 0;
    int n = 1;
    l = 1;
    r = 1;
 
    while (cnt < X)
    {
        cnt += n;
        lrSum++;
        n++;
    }
 
 
    if (n & 1) //n이 홀수
    {
        l = lrSum;
    }
    else //n이 짝수
    {
        r = lrSum;
    }
 
    int CntmnsX = cnt - X;
    for (int i = 0; i < CntmnsX; i++)
    {
        if (n & 1) //n이 홀수면 좌하단에서 우상단으로 이동
        {
            l--;
            r++;
        }
        else //n이 짝수면 우상단에서 좌하단으로 이동
        {
            l++;
            r--;
        }
    }
 
}
 
int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);
 
    cin >> X;
 
    solve();
 
    cout << l << "/" << r;
 
    return 0;
}

