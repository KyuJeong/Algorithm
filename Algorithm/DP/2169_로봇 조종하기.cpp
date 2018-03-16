#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int N, M;
int G[1002][1002];
int DP[1002][1002][2];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> G[i][j];
		}
	}

	memset(DP, -10, sizeof(DP));

	DP[1][1][0] = G[1][1];

	for (int j = 2; j <= M; j++)
	{
		DP[1][j][0] = DP[1][j - 1][0] + G[1][j];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			DP[i][j][0] = max({ DP[i - 1][j][0], DP[i - 1][j][1],DP[i][j - 1][0] }) + G[i][j];
		}

		for (int j = M; j >= 1; j--)
		{
			DP[i][j][1] = max({ DP[i - 1][j][0], DP[i - 1][j][1], DP[i][j + 1][1] }) + G[i][j];
		}
		
	}

	cout << max(DP[N][M][0], DP[N][M][1]);

	return 0;
}