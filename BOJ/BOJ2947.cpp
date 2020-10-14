//https://www.acmicpc.net/problem/2947
#include <iostream>
using namespace std;

int cubeArr[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> cubeArr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (cubeArr[j] > cubeArr[j + 1])
			{
				int tmp = cubeArr[j];
				cubeArr[j] = cubeArr[j + 1];
				cubeArr[j + 1] = tmp;

				for (int i = 0; i < 5; i++)
				{
					cout << cubeArr[i] << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}