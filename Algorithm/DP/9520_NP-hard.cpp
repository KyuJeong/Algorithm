#include <bits/stdc++.h>

using namespace std;

int n;
int d[1501][1501]; // 왼쪽 끝이 i, 오른쪽 끝이 j일 때 드는 시간의 최솟값
int G[1501][1501];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> G[i][j], d[i][j] = 1e9;

	d[1][2] = d[2][1] = G[1][2];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i - 1; j++)
		{
			d[i][i - 1] = min(d[i][i - 1], d[j][i - 1] + G[i][j]);
			d[i][j] = min(d[i][j], d[i - 1][j] + G[i][i - 1]);
			d[i - 1][i] = min(d[i - 1][i], d[i - 1][j] + G[j][i]);
			d[j][i] = min(d[j][i], d[j][i - 1] + G[i - 1][i]);
		}
	}

	int ans = 1e9;
	for (int i = 1; i < n; i++)
		ans = min({ ans,d[i][n],d[n][i] });

	cout << ans;

	return 0;
}