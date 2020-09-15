//https://www.acmicpc.net/problem/10798

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>
using namespace std;

string s[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (j >= s[i].length())
			{
				continue;
			}

			if (s[i][j] != ' ')
			{
				cout << s[i][j];
			}
		}
	}

	return 0;
}