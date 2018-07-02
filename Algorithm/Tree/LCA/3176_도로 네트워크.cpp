#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 1e9

typedef pair <int, int> pii;

vector <pii> G[MAX];
bool visit[MAX];
int parent[MAX];
int P[MAX][18];
int depth[MAX];
int max_len[MAX][18];
int min_len[MAX][18];
int dist[MAX];
int N, M;
int u, v, w;
int h;

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
			int nxt = i.first;
			if (visit[nxt])
				continue;
			visit[nxt] = true;
			parent[nxt] = cur;
			depth[nxt] = depth[cur] + 1;
			dist[nxt] = i.second;

			q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		P[i][0] = parent[i];
		min_len[i][0] = max_len[i][0] = dist[i];
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (P[j][i - 1] != 0)
			{
				P[j][i] = P[P[j][i - 1]][i - 1];
				min_len[j][i] = min( min_len[j][i - 1], min_len[P[j][i - 1]][i - 1] );
				max_len[j][i] = max( max_len[j][i - 1], max_len[P[j][i - 1]][i - 1] );
			}
		}
	}
}

pii LCA(int x, int y)
{
	int _min = INF;
	int _max = -INF;
	if (depth[x] > depth[y])
		swap(x, y);

	int l = (int)ceil(log2(depth[y]));

	for (int i = l; i >= 0; i--)
	{
		if (depth[y] - depth[x] >= (1 << i))
		{
			_min = min(_min, min_len[y][i]);
			_max = max(_max, max_len[y][i]);
			y = P[y][i];
		}
	}

	if (x == y)
		return { _min, _max };

	for (int i = l; i >= 0; i--)
	{
		if (P[x][i] != P[y][i])
		{
			_min = min({ _min, min_len[x][i], min_len[y][i] });
			_max = max({ _max, max_len[x][i], max_len[y][i] });
			x = P[x][i];
			y = P[y][i];
		}
	}

	_min = min({ _min, min_len[x][0], min_len[y][0] });
	_max = max({ _max, max_len[x][0], max_len[y][0] });
	return { _min, _max };
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	h = (int)ceil(log2(N));

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			min_len[i][j] = INF;
			max_len[i][j] = -INF;
		}
	}
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
		pii ans = LCA(u, v);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}