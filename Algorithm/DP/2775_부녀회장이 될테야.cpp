#include <iostream>

using namespace std;

int T, K, N;
int DP[15][15];
int s[15];

int main()
{
	scanf("%d", &T);

	for (int i = 1; i <= 14; i++)
	{
		DP[0][i] = i;
		s[i] = s[i - 1] + i;
	}

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			DP[i][j] = s[j];
			s[j] = s[j - 1] + DP[i][j];
		}
	}

	while (T--)
	{
		scanf("%d %d", &K, &N);

		printf("%d\n", DP[K][N]);
	}
	return 0;
}