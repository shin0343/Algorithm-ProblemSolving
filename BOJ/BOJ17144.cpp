//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct _Cleaner
{
	int topcol;
	int toprow;
	int botcol;
	int botrow;
} Cleaner;

int R, C, T, Ans;
int Map[51][51];
int Append[51][51];
int dc[4] = {1, -1, 0, 0};
int dr[4] = {0, 0, 1, -1};
Cleaner Clnr;

int CntTotalDust()
{
	int sumdust = 0;

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			int tmp = Map[i][j];
			if (tmp == -1 || tmp == 0)
			{
				continue;
			}

			sumdust += Map[i][j];
		}
	}

	return sumdust;
}

void SimulTopCleaner()
{
	//상단 반시계 공기청정기 1회
	int tc = Clnr.topcol;
	int tr = Clnr.toprow;
	int tmpval1, tmpval2;

	tmpval1 = Map[tc][tr + 1];
	Map[tc][tr + 1] = 0;
	for (int i = tr + 2; i < R; i++)
	{
		tmpval2 = Map[tc][i];
		Map[tc][i] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = tc - 1; i >= 0; i--)
	{
		tmpval2 = Map[i][R - 1];
		Map[i][R - 1] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = R - 2; i >= 0; i--)
	{
		tmpval2 = Map[0][i];
		Map[0][i] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = 1; i < tc; i++)
	{
		tmpval2 = Map[i][0];
		Map[i][0] = tmpval1;
		tmpval1 = tmpval2;

		if (i + 1 == tc && 0 == tr)
		{
			return;
		}
	}

	for (int i = 1; i < tr; i++)
	{
		tmpval2 = Map[tc][i];
		Map[tc][i] = tmpval1;
		tmpval1 = tmpval2;
	}
}
void SimulBotCleaner()
{
	//하단 시계 공기청정기 1회
	int bc = Clnr.botcol;
	int br = Clnr.botrow;
	int tmpval1, tmpval2;

	tmpval1 = Map[bc][br + 1];
	Map[bc][br + 1] = 0;
	for (int i = br + 2; i < R; i++)
	{
		tmpval2 = Map[bc][i];
		Map[bc][i] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = bc + 1; i < C; i++)
	{
		tmpval2 = Map[i][R - 1];
		Map[i][R - 1] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = R - 2; i >= 0; i--)
	{
		tmpval2 = Map[C - 1][i];
		Map[C - 1][i] = tmpval1;
		tmpval1 = tmpval2;
	}

	for (int i = C - 2; i > bc; i--)
	{
		tmpval2 = Map[i][0];
		Map[i][0] = tmpval1;
		tmpval1 = tmpval2;

		if (i - 1 == bc && br == 0)
		{
			return;
		}
	}

	for (int i = 1; i < br; i++)
	{
		tmpval2 = Map[br][i];
		Map[br][i] = tmpval1;
		tmpval1 = tmpval2;
	}
}

void Simul()
{
	memset(Append, 0, sizeof(Append));

	//미세먼지 확산 1회
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			int tmp = Map[i][j];

			if (tmp > 0)
			{
				int partofmap = Map[i][j] / 5;
				for (int d = 0; d < 4; d++)
				{
					int nc = i + dc[d];
					int nr = j + dr[d];

					if (nc >= 0 && nr >= 0 && nc < C && nr < R && Map[nc][nr] != -1)
					{
						Append[nc][nr] += partofmap;
						Map[i][j] -= partofmap;
					}
				}
			}
		}
	}

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			int tmp = Append[i][j];
			if (tmp <= 0)
			{
				continue;
			}

			Map[i][j] += tmp;
		}
	}
	memset(Append, 0, sizeof(Append));

	SimulTopCleaner();
	SimulBotCleaner();
}

void Solve()
{
	for (int i = 0; i < T; i++)
	{
		Simul();
	}

	Ans = CntTotalDust();
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	priority_queue<pair<int, int>> pq;

	cin >> C >> R >> T;

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == -1)
			{
				pq.push({i, j});
			}
		}
	}

	Clnr.botcol = pq.top().first;
	Clnr.botrow = pq.top().second;
	pq.pop();
	Clnr.topcol = pq.top().first;
	Clnr.toprow = pq.top().second;
	pq.pop();

	Solve();

	cout << Ans;

	return 0;
}
