#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u;
	int v;
	int w;
};

bool operator < (const Edge &e1, const Edge &e2)
{
	return e1.w < e2.w;
}

int n, m;
int from, to, cost;
int parent[1001];
vector <Edge> G;

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v) return false;

	parent[u] = v;
	return true;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	cin >> from >> to >> cost;
	G.push_back({ from,to,cost });

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> cost;
		G.push_back({ from,to,cost });
	}

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	sort(G.begin(), G.end());

	int cnt[2] = { 0 };
	for (int i = 0; i < G.size(); i++)
	{
		if (merge(G[i].u, G[i].v))
			cnt[0] += 1 - G[i].w;
	}

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	reverse(G.begin(), G.end());

	for (int i = 0; i < G.size(); i++)
	{
		if (merge(G[i].u, G[i].v))
			cnt[1] += 1 - G[i].w;
	}

	cout << cnt[0] * cnt[0] - cnt[1] * cnt[1];

	return 0;
}