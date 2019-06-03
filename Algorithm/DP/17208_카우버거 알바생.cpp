#include <bits/stdc++.h>

using namespace std;

int n;
int a, b, x, y;
int dp[301][301];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> a >> b;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = 1; j <= a; j++)
		{
			for (int k = 1; k <= b; k++)
			{
				if (x <= j && y <= k)
					dp[j - x][k - y] = max(dp[j - x][k - y], dp[j][k] + 1);
			}
		}
	}

	cout << dp[0][0];

	return 0;
}