//https://www.acmicpc.net/problem/15651

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int N, M;

void dfs(string ans, int len)
{
	if (len == M)
	{
		cout << ans << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		dfs(ans + (char)('0' + i) + ' ', len + 1);
	}
}

int main()
{
	cin >> N >> M;

	dfs("", 0);

	return 0;
}