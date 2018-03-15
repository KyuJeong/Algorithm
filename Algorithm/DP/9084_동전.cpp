#include <iostream>

using namespace std;

int T;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int N, M;
		int coin[21];
		int DP[21][10001] = { 0 };

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}
		cin >> M;

		for (int i = 0; i <= N; i++)
		{
			DP[i][0] = 1;
		}

		for (int i = 0; i <= M; i += coin[1])
		{
			DP[1][i] = 1;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				for (int k = 0; k <= j; k += coin[i])
				{
					DP[i][j] += DP[i - 1][j - k];
				}
			}
		}

		cout << DP[N][M] << "\n";

	}

	return 0;
}