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

typedef vector <int> vi;
typedef pair <int, int> pii;

int N, M;
int dist[501];
vector <Edge> edge;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 2; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ u,v,w });
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
			if (u == INF)
				continue;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if (i == N) // N번째에 값이 변경되면 음수사이클 존재
					n_cycle = true;
			}
		}
	}

	if (n_cycle)
	{
		cout << "-1";
		return 0;
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}