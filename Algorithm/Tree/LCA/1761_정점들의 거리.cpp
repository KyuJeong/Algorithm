#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

int N, M;
int u, v, w;
vector <pii> G[40001];
bool visit[40001];
int parent[40001];
int depth[40001];
int dist[40001];
int P[40001][20];
int h;

void BFS()
{
	queue <int> q;
	q.push(1);
	visit[1] = true;
	parent[1] = 0;
	depth[1] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			int nxt = i.first;
			if (visit[nxt])
				continue;
			visit[nxt] = true;
			parent[nxt] = cur;
			depth[nxt] = depth[cur] + 1;
			dist[nxt] = dist[cur] + i.second;

			q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
		P[i][0] = parent[i];

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (P[j][i - 1] != 0)
				P[j][i] = P[P[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);

	int l = (int)ceil(log2(depth[b]));

	for (int i = l; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i))
			b = P[b][i];
	}

	if (a == b)
		return a;

	for (int i = l; i >= 0; i--)
	{
		if (P[a][i] != P[b][i])
		{
			a = P[a][i];
			b = P[b][i];
		}
	}

	return P[a][0];
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	h = (int)ceil(log2(N)); // 트리의 높이

	for (int i = 1; i < N; i++)
	{
		cin >> u >> v >> w;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}

	BFS();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << dist[u] + dist[v] - 2 * dist[LCA(u, v)] << "\n";
	}

	return 0;
}