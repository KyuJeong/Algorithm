#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

typedef long long ll;

ll DP[101][10];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	DP[10][0] = DP[10][9] = 1;

	for (int i = 11; i <= N; i++)
	{
		for (int j = 1; j <= 8; j++)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
	}

	ll ans = 0;

	for (int i = 10; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ans = (ans + DP[i][j]) % MOD;
		}
	}
	cout << ans;

	return 0;
}