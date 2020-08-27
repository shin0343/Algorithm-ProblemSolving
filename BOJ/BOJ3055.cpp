https://www.acmicpc.net/problem/3055
//BOJ 3055
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int R, C; //RÇà C¿­
int Ans = 2e9;
char Map[2500][50][50];
bool Visit[50][50];
int dc[] = { 1, -1, 0, 0 };
int dr[] = { 0 ,0, 1, -1 };

bool IsPromising(int c, int r)
{
	if (c < 0 || r < 0 || c >= R || r >= C)
		return false;

	return true;
}

void NmLater(int n)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			Map[n][i][j] = Map[n - 1][i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[n - 1][i][j] == '*')
			{
				for (int d = 0; d < 4; d++)
				{
					int nc = i + dc[d];
					int nr = j + dr[d];

					if (IsPromising(nc, nr) && Map[n - 1][nc][nr] == '.')
					{
						Map[n][nc][nr] = '*';
					}
				}
			}
		}
	}
}

void SimulBFS(int sc, int sr)
{
	queue<pair<int, pair<int, int>> >  q;
	q.push({ 0,{ sc,sr } });
	Visit[sc][sr] = true;

	while (!q.empty())
	{
		int c = q.front().second.first;
		int r = q.front().second.second;
		int m = q.front().first;
		q.pop();

		if (Map[m][c][r] >= Ans)
		{
			continue;
		}

		if (Map[m][c][r] == 'D')
		{
			Ans = min(Ans, m);
			continue;
		}

		for (int d = 0; d < 4; d++)
		{
			int nc = c + dc[d];
			int nr = r + dr[d];

			if (IsPromising(nc, nr) && (Map[m + 1][nc][nr] == '.' || Map[m + 1][nc][nr] == 'D')
				&& Visit[nc][nr] == false)
			{
				q.push({ m + 1,{ nc,nr } });
				Visit[nc][nr] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	int Bcol, Brow;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[0][i][j];
			if (Map[0][i][j] == 'S')
			{
				Map[0][i][j] = '.';
				Bcol = i;
				Brow = j;
			}
		}
	}

	for (int i = 1; i < R * C; i++)
	{
		NmLater(i);
	}

	SimulBFS(Bcol, Brow);

	if (Ans == 2e9)
		cout << "KAKTUS";
	else
		cout << Ans;

	return 0;
}
