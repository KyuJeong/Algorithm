#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

struct Edge
{
	int from, to, cost;
	Edge() {}
	Edge(int _from, int _to, int _cost)
		: from(_from), to(_to), cost(_cost) {}
};

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int N, M, W;
		int dist[501] = { 0 };
		vector <Edge> edge;
		cin >> N >> M >> W;

		for (int i = 2; i <= N; i++)
			dist[i] = INF;

		for (int i = 0; i < M; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edge.push_back({ u,v,w });
			edge.push_back({ v,u,w });
		}

		for (int i = 0; i < W; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edge.push_back({ u,v,-w });
		}

		dist[1] = 0;

		bool n_cycle = false;

		for (int i = 1; i <= N; i++)
		{
			for (auto j : edge)
			{
				int u = j.from;
				int v = j.to;
				int w = j.cost;

				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					if (i == N)
						n_cycle = true;
				}
			}
		}

		if (n_cycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}