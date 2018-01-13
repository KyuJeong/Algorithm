#include <iostream>
using namespace std;

#define MOD 1000000000

int N, K;
int DP[201][201];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		DP[i][1] = 1;
	}

	for (int j = 1; j <= K; j++)
	{
		DP[1][j] = j;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			DP[i][j] = DP[i - 1][j] % MOD + DP[i][j - 1] % MOD;
		}
	}

	cout << DP[N][K] % MOD;

	return 0;
}