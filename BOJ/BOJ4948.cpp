//https://www.acmicpc.net/problem/4948

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 500000

bool isPrime[MAX];

int main()
{
	int n;
	int ans;
	memset(isPrime, 1, sizeof(isPrime));

	for (int i = 2; i <= MAX; i++)
	{
		for (int j = i + i; j <= MAX; j += i)
		{
			if (isPrime[j] == true)
			{
				isPrime[j] = false;
			}
		}
	}

	while (1)
	{
		ans = 0;
		cin >> n;
		if (n == 0)
		{
			break;
		}

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (isPrime[i])
			{
				ans += 1;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}