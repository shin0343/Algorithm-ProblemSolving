//https://www.acmicpc.net/problem/1182

#include <iostream>
#include <string>
#include <map>
using namespace std;

int Num[21];
bool ChkNum[21];
int N, S;
int Ans;

void dfs(int sum, int idx)
{
	if (idx >= N)
	{
		return;
	}

	sum += Num[idx];

	if (sum == S)
	{
		Ans += 1;
	}

	dfs(sum - Num[idx], idx + 1);
	dfs(sum, idx + 1);
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> Num[i];
	}

	dfs(0, 0);

	cout << Ans;

	return 0;
}