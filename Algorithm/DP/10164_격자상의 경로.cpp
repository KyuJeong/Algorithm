#include <iostream>

using namespace std;

int N, M, K;
int G[16][16];
int DP[226];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	int idx = 1;

	for (int i = 1; i <= N; i++)
	{
		DP[1 + M * (i - 1)] = 1;
		for (int j = 1; j <= M; j++)
		{
			DP[j] = 1;
			G[i][j] = idx++;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			idx = G[i][j];
			DP[idx] = DP[idx - M] + DP[idx - 1];
		}
	}

	int ans;
	if (K == 0)
		ans = DP[N*M];
	else
		ans = DP[K] * DP[N*M - K + 1];

	cout << ans;

	return 0;
}