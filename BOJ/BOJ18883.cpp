#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int seqNum = 1;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", seqNum);
			if (j < M - 1)
			{
				printf(" ");
			}
			seqNum++;
		}
		printf("\n");
	}

	return 0;
}