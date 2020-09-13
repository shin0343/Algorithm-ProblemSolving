//https://www.acmicpc.net/problem/2941

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Ans;

int main()
{
	string s;

	cin >> s;

	int i = 0;
	while (i < s.length())
	{
		if (s[i] == 'c')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == '=' || s[i + 1] == '-')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}
		}
		else if (s[i] == 'd')
		{
			if (i + 1 < s.length())
			{
				if (i + 2 < s.length())
				{
					if (s[i + 1] == 'z' && s[i + 2] == '=')
					{
						Ans += 1;
						i += 3;
						continue;
					}
				}

				if (s[i + 1] == '-')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}

		}
		else if (s[i] == 'l')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == 'j')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}
		}
		else if (s[i] == 'n')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == 'j')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}
		}
		else if (s[i] == 's')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == '=')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}
		}
		else if (s[i] == 'z')
		{
			if (i + 1 < s.length())
			{
				if (s[i + 1] == '=')
				{
					Ans += 1;
					i += 2;
					continue;
				}
			}
		}

		Ans++;
		i++;
	}

	cout << Ans;

	return 0;
}