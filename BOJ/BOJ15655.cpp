//https://www.acmicpc.net/problem/15655

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool chk[9];
int ans[9];
vector<int> num;

void dfs(int idx, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (chk[i] == false)
		{
			chk[i] = true;
			ans[len] = num[i];
			dfs(i + 1, len + 1);
			chk[i] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}

	sort(num.begin(), num.end());

	dfs(0, 0);

	return 0;
}