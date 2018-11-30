#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <pair <int, int>> G[100001];
int u, v;

bool search(int mid)
{
	bool visit[100001] = { false };
	queue <int> q;
	q.push(u);
	visit[u] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto i : G[cur])
		{
			if (i.first >= mid && !visit[i.second])
			{
				if (i.second == v) return true;
				q.push(i.second);
				visit[i.second] = true;
			}
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({ c, b });
		G[b].push_back({ c, a });
	}

	cin >> u >> v;

	int l = 1;
	int r = 1000000000;
	int ans = 1;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (search(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	cout << ans;

	return 0;
}