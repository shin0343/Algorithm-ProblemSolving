//https://www.acmicpc.net/problem/10870

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int pibo[21];

int main()
{
	cin >> n;

	pibo[0] = 0;
	pibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		pibo[i] = pibo[i - 1] + pibo[i - 2];
	}

	cout << pibo[n];

	return 0;
}