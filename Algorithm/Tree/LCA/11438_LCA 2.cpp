#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef vector <int> vi;

vi G[MAX];
int parent[MAX];
int P[MAX][18];
bool visit[MAX];
int depth[MAX];
int u, v;
int N, M, h;

void BFS()
{
	queue <int> q;
	q.push(1);
	visit[1] = true;
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			if (visit[i])
				continue;
			visit[i] = true;
			parent[i] = cur;
			depth[i] = depth[cur] + 1;
			q.push(i);
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

int LCA(int x, int y)
{
	if (depth[x] > depth[y])
		swap(x, y);

	int l = (int) ceil(log2(depth[y]));

	for (int i = l; i >= 0; i--)
	{
		if (depth[y] - depth[x] >= (1 << i))
			y = P[y][i];
	}

	if (x == y)
		return x;

	for (int i = l; i >= 0; i--)
	{
		if (P[x][i] != P[y][i])
		{
			x = P[x][i];
			y = P[y][i];
		}
	}

	return P[x][0];
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	h = (int) ceil(log2(N));

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