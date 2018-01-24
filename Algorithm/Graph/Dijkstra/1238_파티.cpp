#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 99999999

int N, M, X;
vector <vector <pair <int, int>>> G;	// 정방향
vector <vector <pair <int, int>>> R;	// 역방향
int temp1, temp2, temp3;

vector <int> dijkstra(vector <vector <pair <int, int>>> v)
{
	vector <int> dist(N + 1, INF);
	dist[X] = 0;

	priority_queue <pair <int, int>> pq; // 가중치 / 정점

	pq.push(make_pair(0, X));

	while (!pq.empty())
	{
		int cur_cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (dist[cur] < cur_cost)
			continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt_cost = cur_cost + v[cur][i].first;
			int nxt = v[cur][i].second;

			if (dist[nxt] > nxt_cost)
			{
				dist[nxt] = nxt_cost;
				pq.push(make_pair(-nxt_cost, nxt));
			}
		}
	}

	return dist;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> X;

	G.resize(N + 1);
	R.resize(N + 1);

	for (int i = 1; i <= M; i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		G[temp1].push_back(make_pair(temp3, temp2));	// 가중치 / 정점
		R[temp2].push_back(make_pair(temp3, temp1));
	}

	vector<int> dist_G = dijkstra(G);
	vector<int> dist_R = dijkstra(R);

	for (int i = 1; i <= N; i++)
	{
		dist_G[i] += +dist_R[i];
	}

	cout << *max_element(dist_G.begin() + 1, dist_G.end());

	return 0;
}