#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000007

int w, h, x, y;

int DP[201][201];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> w >> h >> x >> y;

	for (int i = 1; i <= y; i++)
	{
		DP[i][1] = 1;
	}

	for (int i = 1; i <= x; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= y; i++)
	{
		for (int j = 2; j <= x; j++)
		{
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
		}
	}

	for (int i = 1; i <= y; i++)
	{
		DP[i][1] = DP[y][x];
	}

	for (int i = 1; i <= x; i++)
	{
		DP[1][i] = DP[y][x];
	}

	for (int i = y; i <= h; i++)
	{
		for (int j = x; j <= w; j++)
		{
			if (i == y && j == x)
				continue;
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
		}
	}

	cout << DP[h][w];

	return 0;
}