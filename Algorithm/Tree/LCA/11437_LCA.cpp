#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int N, M;
vi G[50001];
int u, v;
bool visit[50001];
int depth[50001];
int parent[50001];

void BFS()
{
	queue <int> q;
	q.push(1);
	depth[1] = 0;
	visit[1] = true;
	parent[1] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			if (visit[i])
				continue;
			depth[i] = depth[cur] + 1;
			visit[i] = true;
			parent[i] = cur;

			q.push(i);
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);

	while (depth[a] != depth[b])
	{
		b = parent[b];
	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	BFS();

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}

	return 0;
}