//https://www.acmicpc.net/problem/15654

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> input;
bool use[10001];

void dfs(string ans, int len)
{
	if (len == M)
	{
		cout << ans << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!use[input[i]])
		{
			use[input[i]] = true;
			dfs(ans + to_string(input[i]) + ' ', len + 1);
			use[input[i]] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	dfs("", 0);

	return 0;
}