//https://www.acmicpc.net/submit/11722

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

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;

		for (int j = 1; j < i; j++)
		{
			if (num[i]<num[j] && dp[j] + 1>dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = dp[1];
	for (int i = 2; i <= N; i++)
	{
		max = max < dp[i] ? dp[i] : max;
	}

	cout << max << '\n';

	return 0;
}