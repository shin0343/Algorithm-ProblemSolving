//https://www.acmicpc.net/problem/17142

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define NOTHING 0
#define WALL 1
#define VIRUS 2
#define MAX 50


int maxt, NothingCnt, NothingTmpCnt;
int N, M;
int Ans = 2e9;
int Map[MAX + 1][MAX + 1];
int dc[] = { 1,-1,0,0 };
int dr[] = { 0,0,1,-1 };
bool Visit[MAX + 1][MAX + 1];
bool VisitBFS[MAX + 1][MAX + 1];
vector<pair<int, int> > v;
vector<pair<int, int> > OriginV;

bool IsPossible()
{
	if (NothingCnt == NothingTmpCnt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsPromising(int c, int r, int nct)
{
	if (c >= 0 && r >= 0 && c < N && r < N)
	{
		if (VisitBFS[c][r] == false && Map[c][r] != WALL && nct < Ans)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

void SolveBFS()
{
	queue< pair< pair<int, int>, int> > q;

	for (int vi = 0; vi < v.size(); vi++)
	{
		VisitBFS[v[vi].first][v[vi].second] = true;
		q.push({ { v[vi].first,v[vi].second },0 });
	}

	maxt = 0;
	while (!q.empty())
	{
		int cc = q.front().first.first;
		int cr = q.front().first.second;
		int ct = q.front().second;
		q.pop();

		if (ct >= Ans)
		{
			return;
		}

		if (Map[cc][cr] == NOTHING)
		{
			NothingTmpCnt += 1;
			maxt = max(maxt, ct);
		}

		for (int i = 0; i < 4; i++)
		{
			int nc = cc + dc[i];
			int nr = cr + dr[i];

			if (IsPromising(nc, nr, ct + 1))
			{
				VisitBFS[nc][nr] = true;
				q.push({ { nc,nr }, ct + 1 });
			}
		}
	}

	if (IsPossible())
	{
		Ans = min(Ans, maxt);
	}
}

void GatheringM(int cnt, int vidx)
{
	if (cnt == M)
	{
		NothingTmpCnt = 0;
		memset(VisitBFS, 0, sizeof(VisitBFS));

		SolveBFS();
		return;
	}


	for (int i = vidx + 1; i < OriginV.size(); i++)
	{
		int vc = OriginV[i].first;
		int vr = OriginV[i].second;

		if (Visit[vc][vr])
			continue;

		Visit[vc][vr] = true;
		v.push_back({ vc,vr });
		GatheringM(cnt + 1, i);
		v.pop_back();
		Visit[vc][vr] = false;
	}
}

void SolveAll()
{
	for (int i = 0; i < OriginV.size(); i++)
	{
		int vc = OriginV[i].first;
		int vr = OriginV[i].second;

		Visit[vc][vr] = true;
		v.push_back({ vc,vr });
		GatheringM(1, i);
		v.pop_back();
		Visit[vc][vr] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;

	NothingCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == NOTHING)
			{
				NothingCnt += 1;
			}
			else if (Map[i][j] == VIRUS)
			{
				OriginV.push_back({ i,j });
			}
		}
	}

	SolveAll();

	if (Ans == 2e9)
	{
		cout << -1;
	}
	else
	{
		cout << Ans;
	}

	return 0;
}
