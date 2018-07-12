#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000003

int dp[1001][1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	dp[0][0] = dp[1][0] = dp[1][1] = 1;

	/* 선형으로 생각해서 dp테이블 작성 */
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= K; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	}

	int ans = (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;

	cout << ans;

	return 0;
}