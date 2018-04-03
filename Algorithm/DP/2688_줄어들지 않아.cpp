#include <iostream>

using namespace std;

int T;
long long DP[65][10];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i < 65; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				DP[i][j] += DP[i - 1][k];
			}
		}
	}

	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		long long ans = 0;
		for (int i = 0; i <= 9; i++)
		{
			ans += DP[n][i];
		}

		cout << ans << "\n";
	}

	return 0;
}