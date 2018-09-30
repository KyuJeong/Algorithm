#include <bits/stdc++.h>

using namespace std;

int N, M;
int G[1002][1002];
int d[1002][1002];
int e[1002][1002][2];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> G[i][j];

	for (int i = 1; i <= N; i++)
	{
		d[i][1] = G[i][1];
		e[i][1][0] = e[i][1][1] = G[i][1];
	}

	for (int j = 2; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			d[i][j] = max(d[i - 1][j - 1], d[i + 1][j - 1]);
			d[i][j] = max(d[i][j], d[i][j - 2] + G[i][j - 1]) + G[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
		d[i][M] = max(d[i][M], d[i][M - 1] + G[i][M]);

	for (int j = 2; j <= M; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			e[i][j][0] = max(e[i - 1][j - 1][0], e[i][j - 1][1]) + G[i][j];
			e[i][j][1] = max(e[i + 1][j - 1][1], e[i][j - 1][0]) + G[i][j];
		}
	}

	int _max = 0;
	for (int i = 1; i <= N; i++)
		_max = max({ _max, d[i][M], e[i][M][0],e[i][M][1] });

	cout << _max;

	return 0;
}