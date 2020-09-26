//https://www.acmicpc.net/problem/11053

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int num[1001];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	for (int i = N; i >= 1; i--)
	{
		dp[i] = 1;

		for (int j = i + 1; j <= N; j++)
		{
			if (dp[i] < dp[j] + 1 && num[j] > num[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = dp[N];
	for (int i = N - 1; i >= 1; i--)
	{
		max = max > dp[i] ? max : dp[i];
	}

	cout << max;

	return 0;
}