//https://www.acmicpc.net/problem/16236
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool Visit[21][21];
int Map[21][21];
int Ans;
int N;
int dc[] = {-1, 0, 1, 0};
int dr[] = {0, 1, 0, -1};
int Scol, Srow, Ssize;
int eatN;

bool IsPromising(int c, int r)
{
	if (c >= 0 && r >= 0 && c < N && r < N && Map[c][r] <= Ssize && Visit[c][r] == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SolveAll()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //<거리, <행,열> >

	queue<pair<int, int>> sq;
	sq.push({Scol, Srow});

	queue<pair<pair<int, int>, int>> bfsq;

	while (!sq.empty())
	{
		memset(Visit, 0, sizeof(Visit));

		while (!pq.empty())
			pq.pop();

		int scol = sq.front().first;
		int srow = sq.front().second;
		sq.pop();

		Visit[scol][srow] = true;
		bfsq.push({{scol, srow}, 0});

		while (!bfsq.empty())
		{
			int cc = bfsq.front().first.first;
			int cr = bfsq.front().first.second;
			int cnt = bfsq.front().second;
			bfsq.pop();

			if (Map[cc][cr] > 0 && Map[cc][cr] < Ssize)
			{
				pq.push({cnt, {cc, cr}});
			}

			for (int i = 0; i < 4; i++)
			{
				int nc = cc + dc[i];
				int nr = cr + dr[i];

				if (IsPromising(nc, nr))
				{
					Visit[nc][nr] = true;
					bfsq.push({{nc, nr}, cnt + 1});
				}
			}
		}

		if (!pq.empty())
		{
			eatN += 1;
			Ans += pq.top().first;
			sq.push({pq.top().second.first, pq.top().second.second});
			Map[pq.top().second.first][pq.top().second.second] = 0;

			if (eatN == Ssize)
			{
				Ssize += 1;
				eatN = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 9)
			{
				Map[i][j] = 0;
				Scol = i;
				Srow = j;
			}
		}
	}

	Ssize = 2;
	SolveAll();

	cout << Ans;

	return 0;
}
