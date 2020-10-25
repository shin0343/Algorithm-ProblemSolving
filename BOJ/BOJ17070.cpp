//https://www.acmicpc.net/problem/17070
#include <iostream>
#include <cstring>
using namespace std;

#define DOWN 1
#define RIGHT 2
#define CROSS 3

int N, Ans;
int Map[17][17];
bool Visit[17][17];

bool IsPromising(int c, int r, int d)
{
	if (c < 1 || r < 1 || c > N || r > N || Visit[c][r] || Map[c][r])
	{
		return false;
	}

	if (d == CROSS && c - 1 >= 1 && r - 1 >= 1)
	{
		if (Map[c - 1][r] == 1 || Map[c][r - 1] == 1)
		{
			return false;
		}
	}

	return true;
}

void Solve(int c, int r, int d)
{
	if (c == N && r == N)
	{
		Ans += 1;
		return;
	}

	if (d == RIGHT)
	{
		if (IsPromising(c, r + 1, RIGHT))
		{
			Visit[c][r + 1] = true;
			Solve(c, r + 1, RIGHT);
			Visit[c][r + 1] = false;
		}
		if (IsPromising(c + 1, r + 1, CROSS))
		{
			Visit[c + 1][r + 1] = true;
			Solve(c + 1, r + 1, CROSS);
			Visit[c + 1][r + 1] = false;
		}
	}
	else if (d == DOWN)
	{
		if (IsPromising(c + 1, r, DOWN))
		{
			Visit[c + 1][r] = true;
			Solve(c + 1, r, DOWN);
			Visit[c + 1][r] = false;
		}
		if (IsPromising(c + 1, r + 1, CROSS))
		{
			Visit[c + 1][r + 1] = true;
			Solve(c + 1, r + 1, CROSS);
			Visit[c + 1][r + 1] = false;
		}
	}
	else if (d == CROSS)
	{
		if (IsPromising(c, r + 1, RIGHT))
		{
			Visit[c][r + 1] = true;
			Solve(c, r + 1, RIGHT);
			Visit[c][r + 1] = false;
		}
		if (IsPromising(c + 1, r, DOWN))
		{
			Visit[c + 1][r] = true;
			Solve(c + 1, r, DOWN);
			Visit[c + 1][r] = false;
		}
		if (IsPromising(c + 1, r + 1, CROSS))
		{
			Visit[c + 1][r + 1] = true;
			Solve(c + 1, r + 1, CROSS);
			Visit[c + 1][r + 1] = false;
		}
	}

	return;
}

void SolveAll()
{
	Visit[1][1] = true;
	Visit[1][2] = true;
	Solve(1, 2, RIGHT);
	Visit[1][2] = false;
	Visit[1][1] = false;

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}

	SolveAll();

	cout << Ans;

	return 0;
}