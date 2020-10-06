//https://www.acmicpc.net/problem/10988

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string word;

int main()
{
	cin >> word;

	bool isPel = true;
	for (int i = 0; i < word.length() / 2; i++)
	{
		if (word[i] != word[word.length() - 1 - i])
		{
			isPel = false;
			break;
		}
	}

	if (isPel)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}

	return 0;
}