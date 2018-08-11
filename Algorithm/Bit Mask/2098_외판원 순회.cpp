#include <iostream>
#include <algorithm>

using namespace std;

#define INF 20000000

int N;
int G[17][17];
int DP[17][65536];

int CalCost(int cur, int check)
{
	// 모든 정점을 다 들른 경우
	if (check == ((1 << N) - 1))
	{
		if (G[cur][1] == 0) return INF;
		return G[cur][1];
	}

	// 계산했던 경로인 경우
	if (DP[cur][check])
		return DP[cur][check];

	int val = INF;

	for (int i = 0; i <= N; i++)
	{
		// 방문했던 정점인 경우
		if (check & (1 << (i - 1)))
			continue;

		// 경로가 없을 때
		if (G[cur][i] == 0)
			continue;

		// 경로의 최소값 계산
		int tmp = G[cur][i] + CalCost(i, check + (1 << (i - 1)));
		val = min(val, tmp);
	}

	DP[cur][check] = val;
	return val;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> G[i][j];

	cout << CalCost(1, 1);

	return 0;
}