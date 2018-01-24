#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int from, to, cost;
int indg[101];
int cnt[101][101];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vector <vector <pair <int, int>>> v(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		v[to].push_back(make_pair(from, cost));
		indg[from]++;
	}

	queue <int> q;

	for (int i = 1; i <= N; i++)
	{
		if (!indg[i])
		{
			q.push(i);
			cnt[i][i] = 1;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i].first;
			int nxt_cnt = v[cur][i].second;
			for (int i = 1; i <= N; i++)
				cnt[nxt][i] += cnt[cur][i] * nxt_cnt;
			if (--indg[nxt] == 0)
				q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (cnt[N][i])
			cout << i << " " << cnt[N][i] << "\n";
	}
	return 0;
}