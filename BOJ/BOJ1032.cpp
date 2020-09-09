https://www.acmicpc.net/problem/1032

#include <iostream>
#include <string>
#include <map>
using namespace std;

string Ans;
int AnsLen;
int N;
string S[50];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}

	AnsLen = S[0].length();
	Ans = S[0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < AnsLen; j++)
		{
			if (Ans[j] == S[i][j])
			{
				continue;
			}
			else
			{
				Ans[j] = '?';
			}
		}
	}

	cout << Ans;
	return 0;
}