#include <iostream>

using namespace std;

#define MOD 10007

int N, K;
int DP[1001][1001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		DP[i][0] = 1;
		DP[i][i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (i != j)
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
		}
	}

	cout << DP[N][K];

	return 0;
}