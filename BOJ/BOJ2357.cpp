//https://www.acmicpc.net/problem/2357

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 300005


int n, m;
int minTree[N], maxTree[N], arr[N];

void makeTree(int left, int right, int index)
{
	if (left == right)
	{
		minTree[index] = arr[left];
		maxTree[index] = arr[left];

		return;
	}
	int mid = (left + right) / 2;

	makeTree(left, mid, index * 2);
	makeTree(mid + 1, right, index * 2 + 1);

	minTree[index] = min(minTree[index * 2], minTree[index * 2 + 1]);
	maxTree[index] = max(maxTree[index * 2], maxTree[index * 2 + 1]);
}

int serchminTree(int start, int end, int index, int left, int right)
{
	if (right < start || end < left)
	{
		return -1;
	}
	if (start >= left && end <= right)
	{
		return minTree[index];
	}

	int mid = (start + end) / 2;

	int v1 = serchminTree(start, mid, index * 2, left, right);
	int v2 = serchminTree(mid + 1, end, index * 2 + 1, left, right);

	if (v1 == -1)
	{
		return v2;
	}
	else if (v2 == -1)
	{
		return v1;
	}
	else
	{
		return min(v1, v2);
	}
}

int serchmaxTree(int start, int end, int index, int left, int right)
{
	if (right < start || end < left)
	{
		return -1;
	}
	if (start >= left && end <= right)
	{
		return maxTree[index];
	}

	int mid = (start + end) / 2;

	int v1 = serchmaxTree(start, mid, index * 2, left, right);
	int v2 = serchmaxTree(mid + 1, end, index * 2 + 1, left, right);

	if (v1 == -1)
	{
		return v2;
	}
	else if (v2 == -1)
	{
		return v1;
	}
	else
	{
		return max(v1, v2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	makeTree(1, n, 1);

	int a, b;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		cout << serchminTree(1, n, 1, a, b) << " " << serchmaxTree(1, n, 1, a, b) << '\n';
	}

	return 0;
}