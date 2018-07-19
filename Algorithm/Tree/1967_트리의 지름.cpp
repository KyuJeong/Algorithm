#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef pair <int, int> pii;

vector <pii> G[MAX];
int n;
int u, v, w;
bool visit[MAX];
int idx, ans;

void dfs(int x, int dist)
{
	visit[x] = true;
	if (ans < dist)
		idx = x, ans = dist;
	for (auto i : G[x])
	{
		if (visit[i.first])
			continue;
		dfs(i.first, dist + i.second);
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> u >> v >> w;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}

	dfs(1, 0);

	memset(visit, false, sizeof(visit));
	ans = 0;

	dfs(idx, 0);

	cout << ans;

	return 0;
}