#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 200000000

typedef vector <int> vi;
typedef pair <int, int> pii;

int N, E;
int from, to, c;
int v1, v2;
vector <vector <pii>> G;
int dist[801][3];
int dist2[801][3];

int Dijkstra()
{
	for (int i = 0; i < 3; i++)
	{
		priority_queue <pii> pq;
		
		if (i == 0)
			pq.push({ 0,1 });
		else if (i == 1)
			pq.push({ 0, v1 });
		else
			pq.push({ 0, v2 });

		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (dist[cur][i] < cost)
				continue;

			for (auto j : G[cur])
			{
				int nxt = j.second;
				int ncost = j.first + cost;
				if (dist[nxt][i] > ncost)
				{
					dist[nxt][i] = ncost;
					pq.push({ -ncost,nxt });
				}
			}
		}
	}

	int ret1 = dist[v1][0] + dist[v2][1] + dist[N][2];

	for (int i = 0; i < 3; i++)
	{
		priority_queue <pii> pq;

		if (i == 0)
			pq.push({ 0,1 });
		else if (i == 1)
			pq.push({ 0, v2 });
		else
			pq.push({ 0, v1 });

		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			if (dist2[cur][i] < cost)
				continue;

			for (auto j : G[cur])
			{
				int nxt = j.second;
				int ncost = j.first + cost;
				if (dist2[nxt][i] > ncost)
				{
					dist2[nxt][i] = ncost;
					pq.push({ -ncost,nxt });
				}
			}
		}
	}

	int ret2 = dist2[v2][0] + dist2[v1][1] + dist2[N][2];

	if (ret1 >= INF && ret2 >= INF)
		return -1;
	else
		return min(ret1, ret2);

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> E;

	G.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dist[i][j] = INF;
			dist2[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> c;
		G[from].push_back({ c,to });
		G[to].push_back({ c,from });
	}

	cin >> v1 >> v2;

	dist[1][0] = 0;
	dist[v1][1] = 0;
	dist[v2][2] = 0;
	dist2[1][0] = 0;
	dist2[v2][1] = 0;
	dist2[v1][2] = 0;

	int ans = Dijkstra();

	cout << ans;

	return 0;
}