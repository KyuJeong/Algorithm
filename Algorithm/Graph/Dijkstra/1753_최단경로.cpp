#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 100000000

using namespace std;

int V, E;
int K;
int from, to, weight;
int ans[20001];

vector <vector <pair <int, int>>> v;
priority_queue <pair <int, int>> pq;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> V >> E;
	cin >> K;

	v.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(weight, to));
	}

	vector <int> dist(V + 1, INF);
	dist[K] = 0;

	for (int i = 0; i < v[K].size(); i++)
	{
		int nxt_cost = v[K][i].first;
		int nxt_vtx = v[K][i].second;
		pq.push(make_pair(-nxt_cost, nxt_vtx));
		if (dist[nxt_vtx] > nxt_cost)
			dist[nxt_vtx] = nxt_cost;
	}

	while (!pq.empty())
	{
		int cur_cost = -pq.top().first;
		int cur_vtx = pq.top().second;

		pq.pop();

		if (dist[cur_vtx] < cur_cost)
			continue;

		for (int i = 0; i < v[cur_vtx].size(); i++)
		{
			int next_cost = v[cur_vtx][i].first + cur_cost;
			int next_vtx = v[cur_vtx][i].second;
			if (dist[next_vtx] > next_cost)
			{
				dist[next_vtx] = next_cost;
				pq.push(make_pair(-next_cost, next_vtx));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}