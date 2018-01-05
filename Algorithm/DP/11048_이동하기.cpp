#include <iostream>
using namespace std;

int DP[1000][1000];

int main()
{
	std::ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> DP[i][j];
		}
	}

	for (int i = 1; i < N; i++)
	{
		DP[i][0] = DP[i - 1][0] + DP[i][0];
	}

	for (int j = 1; j < M; j++)
	{
		DP[0][j] = DP[0][j - 1] + DP[0][j];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (DP[i - 1][j] > DP[i][j - 1])
				DP[i][j] = DP[i - 1][j] + DP[i][j];
			else
				DP[i][j] = DP[i][j - 1] + DP[i][j];
		}
	}

	printf("%d", DP[N - 1][M - 1]);

	return 0;
}