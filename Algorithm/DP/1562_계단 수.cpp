#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

typedef long long ll;

int N;
ll dp[101][10][1025];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i <= 9; i++)
		dp[1][i][(1 << i)] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 1023; k++)
			{
				if (j == 0)
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
				else if (j == 9)
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
				else
					dp[i][j][k | (1 << j)] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]);
				dp[i][j][k | (1 << j)] %= MOD;
			}
		}
	}

	ll ans = 0;

	for (int j = 1; j <= 9; j++)
		ans = (ans + dp[N][j][1023]) % MOD;

	cout << ans;

	return 0;
}