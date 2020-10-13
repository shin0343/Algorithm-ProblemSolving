//https://www.acmicpc.net/problem/2460

#include <iostream>
using namespace std;

int main()
{
	int ans = 0;
	int total = 0;
	int in, out;

	for (int i = 0; i < 10; i++)
	{
		cin >> out >> in;

		total -= out;
		total += in;
		ans = total > ans ? total : ans;
	}

	cout << ans;

	return 0;
}