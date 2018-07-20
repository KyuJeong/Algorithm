#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009

int N, M;
char G[3001][3001];
int dp[3001][3001];
int ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	char tmp;
	for (int i = 0; i < N; i++)
			cin >> G[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dp[i][j]++;
			if (G[i][j] == 'X') break;

			if (G[i][j] == 'E')
				dp[i][j + 1] += dp[i][j] % MOD;
			else if (G[i][j] == 'S')
				dp[i + 1][j] += dp[i][j] % MOD;
			else if (G[i][j] == 'B')
			{
				dp[i][j + 1] += dp[i][j] % MOD;
				dp[i + 1][j] += dp[i][j] % MOD;
			}
		}
	}

	ans = dp[N - 1][M - 1] % MOD;
	cout << ans;

	return 0;
}