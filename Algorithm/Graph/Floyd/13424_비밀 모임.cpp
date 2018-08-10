#include <bits/stdc++.h>

using namespace std;

#define INF 1e8

int t;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int G[101][101] = { 0 };
		int u, v, w;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
					G[i][j] = INF;
			}
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			G[u][v] = w;
			G[v][u] = w;
		}

		int k;
		cin >> k;
		vector <int> f(k);
		for (int i = 0; i < k; i++)
			cin >> f[i];

		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++)
			{
				if (G[j][i] == INF) continue;
				for (int k = 1; k <= n; k++)
				{
					if (G[j][k] > G[j][i] + G[i][k])
						G[j][k] = G[j][i] + G[i][k];
				}
			}
		}
		
		int _min = INF;
		int idx = n;
		for (int i = n; i >= 1; i--)
		{
			int tmp = 0;
			for (auto j : f)
				tmp += G[i][j];
			if (_min >= tmp)
				_min = tmp, idx = i;
		}
		cout << idx << "\n";
	}

	return 0;
}