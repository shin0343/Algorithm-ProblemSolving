//https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CCTV
{
public:
	CCTV(int c, int r, int t)
	{
		col = c;
		row = r;
		type = t;
	}
	int col;
	int row;
	int type;
};

int Map[9][9];
int Bmap[9][9][9];
bool Visit[9][9];
int N, M;
int Ans = 2e9;
vector<CCTV> Cams;

void BackupMap(int layer)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Bmap[layer][i][j] = Map[i][j];
		}
	}
}

void RestoreMap(int layer)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Map[i][j] = Bmap[layer][i][j];
		}
	}
}

int CountAns()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 0)
			{
				cnt += 1;
			}
		}
	}

	return cnt;
}

void ChkUp(int col, int row)
{
	for (int j = col - 1; j >= 0; j--)
	{
		if (Map[j][row] == 6)
			break;

		if (Map[j][row] >= 1 && Map[j][row] <= 5)
			continue;

		Map[j][row] = -1;
	}
}

void ChkDown(int col, int row)
{
	for (int j = col + 1; j < N; j++)
	{
		if (Map[j][row] == 6)
			break;

		if (Map[j][row] >= 1 && Map[j][row] <= 5)
			continue;

		Map[j][row] = -1;
	}
}

void ChkLeft(int col, int row)
{
	for (int j = row - 1; j >= 0; j--)
	{
		if (Map[col][j] == 6)
			break;

		if (Map[col][j] >= 1 && Map[col][j] <= 5)
			continue;

		Map[col][j] = -1;
	}
}

void ChkRight(int col, int row)
{
	for (int j = row + 1; j < M; j++)
	{
		if (Map[col][j] == 6)
			break;

		if (Map[col][j] >= 1 && Map[col][j] <= 5)
			continue;

		Map[col][j] = -1;
	}
}

void SolveDFS(int c, int r, int type, int cnt, int idx)
{
	if (Ans == 0)
	{
		return;
	}

	if (cnt == Cams.size())
	{
		Ans = min(Ans, CountAns());
		return;
	}

	for (int i = idx + 1; i < Cams.size(); i++)
	{
		if (Visit[Cams[i].col][Cams[i].row] == false)
		{
			if (Cams[i].type == 1)
			{
				BackupMap(i);
				ChkUp(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkDown(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkLeft(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;
			}
			else if (Cams[i].type == 2)
			{
				BackupMap(i);
				ChkUp(Cams[i].col, Cams[i].row);
				ChkDown(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkLeft(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;
			}
			else if (Cams[i].type == 3)
			{
				BackupMap(i);
				ChkUp(Cams[i].col, Cams[i].row);
				ChkLeft(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkUp(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkDown(Cams[i].col, Cams[i].row);
				ChkLeft(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkDown(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;
			}
			else if (Cams[i].type == 4)
			{
				BackupMap(i);

				ChkUp(Cams[i].col, Cams[i].row);
				ChkLeft(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkUp(Cams[i].col, Cams[i].row);
				ChkLeft(Cams[i].col, Cams[i].row);
				ChkDown(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkLeft(Cams[i].col, Cams[i].row);
				ChkDown(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;

				//BackupMap();
				ChkUp(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				ChkDown(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;
			}
			else if (Cams[i].type == 5)
			{
				BackupMap(i);
				ChkUp(Cams[i].col, Cams[i].row);
				ChkDown(Cams[i].col, Cams[i].row);
				ChkLeft(Cams[i].col, Cams[i].row);
				ChkRight(Cams[i].col, Cams[i].row);
				Visit[Cams[i].col][Cams[i].row] = true;
				SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, cnt + 1, i);
				RestoreMap(i);
				Visit[Cams[i].col][Cams[i].row] = false;
			}
		}
	}
}

void SolveAll()
{
	for (int i = 0; i <= 0; i++)
	{
		if (Cams[i].type == 1)
		{
			BackupMap(i);
			ChkUp(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkDown(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkLeft(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;
		}
		else if (Cams[i].type == 2)
		{
			BackupMap(i);
			ChkUp(Cams[i].col, Cams[i].row);
			ChkDown(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkLeft(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;
		}
		else if (Cams[i].type == 3)
		{
			BackupMap(i);
			ChkUp(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkUp(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkDown(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkDown(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;
		}
		else if (Cams[i].type == 4)
		{
			BackupMap(i);
			ChkUp(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkUp(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			ChkDown(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkDown(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;

			//BackupMap();
			ChkUp(Cams[i].col, Cams[i].row);
			ChkDown(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;
		}
		else if (Cams[i].type == 5)
		{
			BackupMap(i);
			ChkUp(Cams[i].col, Cams[i].row);
			ChkDown(Cams[i].col, Cams[i].row);
			ChkLeft(Cams[i].col, Cams[i].row);
			ChkRight(Cams[i].col, Cams[i].row);
			Visit[Cams[i].col][Cams[i].row] = true;
			SolveDFS(Cams[i].col, Cams[i].row, Cams[i].type, 1, i);
			RestoreMap(i);
			Visit[Cams[i].col][Cams[i].row] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			Map[i][j] = tmp;

			if (tmp >= 1 && tmp <= 5)
			{
				Cams.push_back(CCTV(i, j, tmp));
			}
		}
	}

	if (Cams.size() == 0)
	{
		Ans = CountAns();
	}
	else
	{
		SolveAll();
	}

	cout << Ans;

	return 0;
}
