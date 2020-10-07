//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Visit[51][51];
int N, M;
int Ans = 2e9;
vector<pair<int, int> > Chkns; //<col,row>
vector<pair<int, int> > Homes; //<col,row>

int CalDist()
{
	int sum = 0;

	for (int i = 0; i < Homes.size(); i++)
	{
		int tmpSum = 2e9;

		for (int j = 0; j < Chkns.size(); j++)
		{
			if (Visit[Chkns[j].first][Chkns[j].second])
			{
				tmpSum = min(tmpSum, (abs(Homes[i].first - Chkns[j].first)
					+ abs(Homes[i].second - Chkns[j].second)));
			}
		}

		sum += tmpSum;
	}

	return sum;
}

void SimulDFS(int idx, int cnt)
{
	if (cnt == M)
	{
		Ans = min(Ans, CalDist());
		return;
	}

	if (idx + 1 >= Chkns.size())
		return;

	Visit[Chkns[idx + 1].first][Chkns[idx + 1].second] = true;
	SimulDFS(idx + 1, cnt + 1);
	Visit[Chkns[idx + 1].first][Chkns[idx + 1].second] = false;

	SimulDFS(idx + 1, cnt);
}

void SimulAll()
{
	Visit[Chkns[0].first][Chkns[0].second] = true;
	SimulDFS(0, 1);
	Visit[Chkns[0].first][Chkns[0].second] = false;

	SimulDFS(0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;

			if (input == 2)
			{
				Chkns.push_back({ i,j });
			}
			if (input == 1)
			{
				Homes.push_back({ i,j });
			}
		}
	}

	SimulAll();

	cout << Ans;

	return 0;
}
