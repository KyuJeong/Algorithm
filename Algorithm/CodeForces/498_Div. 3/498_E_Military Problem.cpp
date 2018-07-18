#include <bits/stdc++.h>

using namespace std;

int N;

vector <int> G[200001];
int key[200001];
int seq[200001];
bool visit[200001];
int child[200001];
int idx = 1;

int dfs(int x, int cnt)
{
	visit[x] = true;
	key[idx] = x;
	seq[x] = idx++;
	for (auto i : G[x])
	{
		if (visit[i])
			continue;
		child[x] += dfs(i, 0);
	}
	return child[x] + 1;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	int u;
	for (int i = 2; i <= n; i++)
	{
		cin >> u;
		G[u].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		sort(G[i].begin(), G[i].end());

	dfs(1, 0);

	int a, b;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		if (b == 1)
		{
			cout << a << "\n";
			continue;
		}
		int nxt = seq[a] + b - 1;
		if (child[a] + 1 < b)
			cout << "-1\n";
		else
			cout << key[nxt] << "\n";
	}

	return 0;
}