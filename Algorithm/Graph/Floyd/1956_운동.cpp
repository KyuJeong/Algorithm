#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int V, E;
int dist[401][401];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;
	}

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[j][i] == INF)
				continue;
			for (int k = 1; k <= V; k++)
			{
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	int ans = 1e9;

	for (int i = 1; i <= V; i++)
	{
		if (ans > dist[i][i])
			ans = dist[i][i];
	}

	if (ans == INF)
		cout << "-1";
	else
		cout << ans;

	return 0;
}