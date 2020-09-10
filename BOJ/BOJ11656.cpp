https://www.acmicpc.net/problem/11656

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s.substr(i, s.length() - i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}