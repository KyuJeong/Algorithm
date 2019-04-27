#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef pair <int, int> pii;
int n, m;
vector <pii> v[501];
int dist[501];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto k : v[j])
			{
				if (dist[j] != INF && dist[k.first] > dist[j] + k.second)
				{
					dist[k.first] = dist[j] + k.second;
					if (i == n)
					{
						cout << "-1";
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF) dist[i] = -1;
		cout << dist[i] << "\n";
	}

	return 0;
}