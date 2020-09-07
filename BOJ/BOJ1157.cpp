https://www.acmicpc.net/problem/1157

//BOJ 1157
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<char, int> dictionary;
	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a')
		{
			s[i] -= ('a' - 'A');
		}

		auto itr = dictionary.find(s[i]);

		if (itr != dictionary.end())
		{
			dictionary[itr->first] += 1;
		}
		else
		{
			dictionary[s[i]] = 1;
		}
	}

	//cout << s;

	auto maxItr = dictionary.begin();
	auto Itr = dictionary.begin()++;
	for (Itr = dictionary.begin(); Itr != dictionary.end(); Itr++)
	{
		if (maxItr->second < Itr->second)
		{
			maxItr = Itr;
		}
	}

	for (Itr = dictionary.begin(); Itr != dictionary.end(); Itr++)
	{
		if (Itr->second == maxItr->second && Itr->first != maxItr->first)
		{
			cout << "?\n";
			return 0;
		}
	}

	cout << maxItr->first << "\n";

	return 0;
}