#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef pair <int, int> pii;

int dist_j[101];
int dist_s[101];
int n, m, j, s;
vector <vector <pii>> v;

void dijkstra()
{
	priority_queue <pii, vector <pii>, greater <pii>> pq;
	pq.push({ 0,j });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		if (dist_j[cur] < cur_dist)
			continue;

		for (auto i : v[cur])
		{
			int nxt = i.second;
			int nxt_dist = cur_dist + i.first;
			if (dist_j[nxt] > nxt_dist)
			{
				dist_j[nxt] = nxt_dist;
				pq.push({ nxt_dist,nxt });
			}
		}
	}

	pq.push({ 0,s });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		if (dist_s[cur] < cur_dist)
			continue;

		for (auto i : v[cur])
		{
			int nxt = i.second;
			int nxt_dist = cur_dist + i.first;
			if (dist_s[nxt] > nxt_dist)
			{
				dist_s[nxt] = nxt_dist;
				pq.push({ nxt_dist,nxt });
			}
		}
	}
}

int solve()
{
	int dist = INF;
	int ret = -1;

	for (int i = 1; i <= n; i++)
	{
		if (i == j || i == s) continue;
		if (dist > dist_j[i] + dist_s[i])
			dist = dist_j[i] + dist_s[i];
	}
	if (dist == INF) return ret;

	int _min = INF;
	for (int i = 1; i <= n; i++)
	{
		if (i == j || i == s) continue;
		if (dist_j[i] > dist_s[i]) continue;
		if (dist == dist_j[i] + dist_s[i])
		{
			if (_min > dist_j[i])
			{
				_min = dist_j[i];
				ret = i;
			}
		}
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost,to });
		v[to].push_back({ cost,from });
	}

	for (int i = 1; i <= 100; i++)
		dist_j[i] = dist_s[i] = INF;

	cin >> j >> s;

	dijkstra();

	int ans = solve();
	cout << ans;

	return 0;
}