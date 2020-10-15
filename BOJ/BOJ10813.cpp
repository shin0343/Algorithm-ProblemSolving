//https://www.acmicpc.net/problem/10813
#include <iostream>
using namespace std;

int n, m;
int bucket[101];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= 100; i++)
	{
		bucket[i] = i;
	}

	int a, b;
	int tmp;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		tmp = bucket[a];
		bucket[a] = bucket[b];
		bucket[b] = tmp;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << bucket[i] << ' ';
	}

	return 0;
}