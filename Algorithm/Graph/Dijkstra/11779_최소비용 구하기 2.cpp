#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1e9

typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;
int src, dst;
vector <vector <pii>> G;
int from, go, edge;
vector <int> dist;
int parent[1001];

void Dijkstra()
{
	priority_queue <pii> pq;

	pq.push({ 0,src });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (auto i : G[cur])
		{
			int nxt = i.second;
			int ncost = i.first + cost;
			if (dist[nxt] > ncost)
			{
				dist[nxt] = ncost;
				pq.push({ -ncost,nxt });
				parent[nxt] = cur;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	G.resize(n + 1);
	dist.resize(n + 1);

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		cin >> from >> go >> edge;
		G[from].push_back({ edge,go });
	}

	cin >> src >> dst;

	Dijkstra();

	vector <int> trace;
	int idx = dst;
	trace.push_back(dst);
	while (idx != src)
	{
		int nidx = parent[idx];
		trace.push_back(nidx);
		idx = nidx;
	}

	cout << dist[dst] << "\n";
	cout << trace.size() << "\n";
	for (int i = trace.size() - 1; i >= 0; i--)
	{
		cout << trace[i] << " ";
	}

	return 0;
}