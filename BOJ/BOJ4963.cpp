//BOJ 4963
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int w, h;
int Ans;
int Map[50][50];
bool Visit[50][50];
int dc[] = { 1,-1,0,0,1,-1,1,-1 };
int dr[] = { 0,0,1,-1,1,-1,-1,1 };

int SimulBFS(int sc, int sr)
{
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push({ sc,sr });
	Visit[sc][sr] = true;

	while (!q.empty())
	{
		int c = q.front().first;
		int r = q.front().second;
		q.pop();

		for (int d = 0; d < 8; d++)
		{
			int nc = c + dc[d];
			int nr = r + dr[d];

			if (nc < 0 || nr < 0 || nc >= h || nr >= w || Visit[nc][nr] || Map[nc][nr] == 0)
				continue;

			q.push({ nc,nr });
			Visit[nc][nr] = true;
			cnt += 1;
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		memset(Visit, false, sizeof(Visit));
		Ans = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> Map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (Map[i][j] == 1 && Visit[i][j] == false)
				{
					if (SimulBFS(i, j) >= 1)
						Ans += 1;
				}
			}
		}

		cout << Ans << '\n';
	}

	return 0;
}
