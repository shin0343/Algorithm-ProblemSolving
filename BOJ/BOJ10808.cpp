https://www.acmicpc.net/problem/10808

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

string S;

int main()
{
	map<char, int> m;
	cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		auto itr = m.find(S[i]);

		if (itr != m.end())
		{
			m[S[i]] += 1;
		}
		else
		{
			m[S[i]] = 1;
		}
	}

	for (char i = 'a'; i <= 'z'; i++)
	{
		cout << m[i] << " ";
	}

	return 0;
}