//https://www.acmicpc.net/problem/14681

#include <iostream>
#include <cstring>
using namespace std;

int FindQuadrant(int x, int y)
{
	if (x > 0 && y > 0)
	{
		return 1;
	}

	if (x < 0 && y > 0)
	{
		return 2;
	}

	if (x < 0 && y < 0)
	{
		return 3;
	}

	if (x > 0 && y < 0)
	{
		return 4;
	}
}

int main()
{
	int x, y;

	cin >> x >> y;

	cout << FindQuadrant(x, y);

	return 0;
}