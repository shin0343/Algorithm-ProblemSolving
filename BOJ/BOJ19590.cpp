#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;

int main() {
	ll totalBid = 0;
	int maxBid = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (N == 1)
		{
			cout << a;
			return 0;
		}

		totalBid += a;
		maxBid = max(maxBid, a);
	}

	if (totalBid - maxBid > maxBid)
	{
		cout << (totalBid & 1);
	}
	else
	{
		cout << maxBid - (totalBid - maxBid);
	}


	return 0;
}