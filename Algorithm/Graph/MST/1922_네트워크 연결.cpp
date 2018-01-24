#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int N, M;
vector <vector <pair <int, int>>> v;
int from, to, cost;
int ans;
bool visit[1001];

void Prim()
{
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;

		pq.pop();

		if (visit[cur])
			continue;
		visit[cur] = true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i].second;
			int nxt_cost = v[cur][i].first;

			pq.push(make_pair(nxt_cost, nxt));
		}
		ans += cur_cost;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	v.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(cost, to));
		v[to].push_back(make_pair(cost, from));
	}

	Prim();

	cout << ans;

	return 0;
}