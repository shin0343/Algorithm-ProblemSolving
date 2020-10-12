//https://www.acmicpc.net/problem/2163

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int ans;
	int N, M;

	cin >> N >> M;

	if (N > M)
	{
		ans = (N - 1) + (N*(M - 1));
	}
	else
	{
		ans = (M - 1) + (M*(N - 1));
	}

	cout << ans;

	return 0;
}