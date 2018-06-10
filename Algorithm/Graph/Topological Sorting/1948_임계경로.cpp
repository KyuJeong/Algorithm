#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;
vector <pii> G[10001];
vector <pii> R[10001];
int ind[10001];
int r_ind[10001];
bool contain[10001];
int dist[10001];
int s, f;
int ans_cnt;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({ v,w });
		R[v].push_back({ u,w });
		ind[v]++;
		r_ind[u]++;
	}

	queue <int> q;

	cin >> s >> f;

	q.push(s);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			int nc = dist[cur] + i.second;
			int ni = i.first;
			if (nc > dist[ni])
				dist[ni] = nc;

			if (--ind[ni] == 0)
				q.push(ni);
		}
	}

	q.push(f);
	contain[f] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : R[cur])
		{
			int nc = i.second;
			int ni = i.first;

			if (--r_ind[ni] == 0)
				q.push(ni);

			if (!contain[cur])
				continue;

			if (dist[cur] - nc == dist[ni])
			{
				ans_cnt++;
				contain[ni] = true;
			}
		}
	}

	cout << dist[f] << "\n" << ans_cnt;

	return 0;
}