//https://www.acmicpc.net/problem/15650

#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
bool ChkNum[9];

void dfs(string ans, int ansLen, int curNum)
{
	if (ansLen == M)
	{
		cout << ans << "\n";
	}

	for (int i = curNum + 1; i <= N; i++)
	{
		if (ChkNum[i])
		{
			continue;
		}

		ChkNum[i] = true;
		dfs(ans + char(i + '0') + ' ', ansLen + 1, i);
		ChkNum[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	dfs("", 0, 0);

	return 0;
}