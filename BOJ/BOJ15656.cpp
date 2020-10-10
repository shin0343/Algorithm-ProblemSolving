//https://www.acmicpc.net/problem/15656

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nNum[8];
int mNum[8];

void dfs(int idx, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << mNum[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		mNum[len] = nNum[i];
		dfs(i + 1, len + 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> nNum[i];
	}

	sort(nNum, nNum + N);

	dfs(0, 0);

	return 0;
}