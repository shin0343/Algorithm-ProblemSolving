https://www.acmicpc.net/problem/1316

//BOJ 1316
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int N;
int ans;
string words[100];

int main()
{
	cin >> N;
	map<char, int> m;

	for (int i = 0; i < N; i++)
	{
		int isGroupWord = 1;
		m.clear();
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++)
		{
			auto itr = m.find(words[i][j]);
			if (itr == m.end())
			{
				m[words[i][j]] = 1;
			}
			else if (words[i][j] != words[i][j - 1])
			{
				isGroupWord = 0;
				break;
			}
		}

		if (isGroupWord)
		{
			ans += 1;
		}
	}

	cout << ans;


	return 0;
}