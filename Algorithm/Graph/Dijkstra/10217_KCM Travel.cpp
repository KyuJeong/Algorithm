#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2147483647

struct Edge
{
	int to;
	int pay;
	int weight;
	Edge()
	{}
	Edge(int _to, int _pay, int _weight)
	{
		to = _to;
		pay = _pay;
		weight = _weight;
	}
};

bool operator< (const Edge &edge1, const Edge &edge2)
{
	return edge1.weight > edge2.weight;
}

int T;
int N, M, K;
int from, to, pay, weight;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d %d", &N, &M, &K);
		vector <Edge> v[101];
		priority_queue <Edge> pq;
		vector <vector <int>> dist(N + 1, vector <int>(M + 1, INF));


		for (int i = 0; i < K; i++)
		{
			scanf("%d %d %d %d", &from, &to, &pay, &weight);
			v[from].push_back(Edge(to, pay, weight));
		}

		pq.push(Edge(1, 0, 0));

		dist[1][0] = 0;

		while (!pq.empty())
		{
			int cur_cost = pq.top().weight;
			int cur_vtx = pq.top().to;
			int cur_pay = pq.top().pay;

			pq.pop();

			if (cur_vtx != 1 && cur_cost > dist[cur_vtx][cur_pay])
				continue;

			if (cur_vtx == N)
				break;

			for (int i = 0; i < v[cur_vtx].size(); i++)
			{
				int nxt_cost = v[cur_vtx][i].weight + cur_cost;
				int nxt_vtx = v[cur_vtx][i].to;
				int nxt_pay = v[cur_vtx][i].pay + cur_pay;

				if (nxt_pay > M)
					continue;

				if (dist[nxt_vtx][nxt_pay] > nxt_cost)
				{
					dist[nxt_vtx][nxt_pay] = nxt_cost;
					pq.push(Edge(nxt_vtx, nxt_pay, nxt_cost));
				}
			}
		}

		int ans = INF;

		for (int i = 1; i <= M; i++)
		{
			if (dist[N][i] != INF)
				ans = min(ans, dist[N][i]);
		}

		if (ans == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", ans);

	}

	return 0;
}