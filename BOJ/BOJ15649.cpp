https://www.acmicpc.net/problem/15649

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
bool numChk[9];

void dfs(string ans, int len)
{
	if (len == M)
	{
		cout << ans << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (numChk[i])
		{
			continue;
		}

		numChk[i] = true;
		dfs(ans + (char)('0' + i) + ' ', len + 1);
		numChk[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	dfs("", 0);

	return 0;
}