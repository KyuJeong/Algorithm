#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX 10001

using namespace std;
int V, E;
int from, to, weight;
int weight_sum;
bool visit[MAX];
int ans;

vector <vector <pair <int, int>>> v;
priority_queue <pair<int, int>, vector <pair <int, int>>, greater<pair<int, int>>> pq;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> V >> E;

	v.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;

		v[from].push_back(make_pair(weight, to));
		v[to].push_back(make_pair(weight, from));
	}

	for (int i = 0; i < v[1].size(); i++)
	{
		int nxt_cost = v[1][i].first;
		int nxt_vertex = v[1][i].second;
		pq.push(make_pair(nxt_cost, nxt_vertex));
	}

	visit[1] = true;

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur_vertex = pq.top().second;
		pq.pop();

		if (visit[cur_vertex])
			continue;

		visit[cur_vertex] = true;

		ans += cur_cost;

		for (int i = 0; i < v[cur_vertex].size(); i++)
		{
			int nxt_cost = v[cur_vertex][i].first;
			int nxt_vertex = v[cur_vertex][i].second;

			pq.push(make_pair(nxt_cost, nxt_vertex));
		}
	}

	cout << ans;

	return 0;
}