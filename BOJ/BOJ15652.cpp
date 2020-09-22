//https://www.acmicpc.net/problem/15652

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int N, M;

void dfs(string ans, int len, int cur)
{
	if (len == M)
	{
		cout << ans << "\n";
		return;
	}

	for (int i = cur; i <= N; i++)
	{
		dfs(ans + (char)('0' + i) + ' ', len + 1, i);
	}
}

int main()
{
	cin >> N >> M;

	dfs("", 0, 1);

	return 0;
}