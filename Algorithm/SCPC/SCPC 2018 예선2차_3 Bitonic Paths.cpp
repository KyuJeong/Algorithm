#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 100001

const ll INF = 10000000000000000LL;

struct Edge
{
	ll weight;
	int nxt;
	Edge() {};
	Edge(ll _weight, int _nxt) :
		weight(_weight), nxt(_nxt) {};
};

struct Ele
{
	ll weight;
	ll dist;
	int nxt;
	int pre;
	Ele() {};
	Ele(ll _weight, ll _dist, int _nxt, int _pre) :
		weight(_weight), dist(_dist), nxt(_nxt), pre(_pre) {};
};

bool operator < (const Edge &edge1, const Edge &edge2)
{
	return edge1.weight < edge2.weight;
}

bool operator < (const Ele &ele1, const Ele &ele2)
{
	return ele1.weight > ele2.weight;
}

vector <Edge> G[MAX];
ll srt_dist[MAX];
ll dst_dist[MAX];
int pre[MAX];
int pos[MAX];
int tmp[MAX];
int N, M;
map <int, int> m;

void init()
{
	for (int i = 1; i <= N; i++)
	{
		G[i].clear();
		srt_dist[i] = INF;
		dst_dist[i] = INF;
	}
	memset(pre, 0, sizeof(pre));
	memset(pos, 0, sizeof(pos));
}

void srtDijkstra()
{
	priority_queue <Ele> pq;
	pq.push({ 0,0,1,0 });

	srt_dist[1] = 0;

	int idx = 0;

	while (!pq.empty())
	{
		Ele c = pq.top();
		ll cur_weight = c.weight;
		ll cur_dist = c.dist;
		int cur = c.nxt;
		int pre = c.pre;

		pq.pop();

		if (srt_dist[cur] > srt_dist[pre] + cur_weight)
			srt_dist[cur] = srt_dist[pre] + cur_weight;

		if (pos[cur] >= G[cur].size())
			continue;

		while (pos[cur] < G[cur].size())
		{
			int nxt = G[cur][pos[cur]].nxt;
			if (nxt == pre || cur_weight > G[cur][pos[cur]].weight)
			{
				pos[cur]++;
				continue;
			}
			ll nxt_weight = G[cur][pos[cur]].weight;
			ll nxt_dist = srt_dist[cur] + nxt_weight;
			pq.push({ nxt_weight, nxt_dist, nxt, cur });

			pos[cur]++;
		}
	}
}

void dstDijkstra()
{
	priority_queue <Ele> pq;
	pq.push({ 0,0,N,0 });

	dst_dist[N] = 0;

	int idx = 0;

	while (!pq.empty())
	{
		Ele c = pq.top();
		ll cur_weight = c.weight;
		ll cur_dist = c.dist;
		int cur = c.nxt;
		int pre = c.pre;

		pq.pop();

		if (dst_dist[cur] > dst_dist[pre] + cur_weight)
			dst_dist[cur] = dst_dist[pre] + cur_weight;

		if (pos[cur] >= G[cur].size())
			continue;

		while (pos[cur] < G[cur].size())
		{
			int nxt = G[cur][pos[cur]].nxt;
			if (nxt == pre || cur_weight > G[cur][pos[cur]].weight)
			{
				pos[cur]++;
				continue;
			}
			ll nxt_weight = G[cur][pos[cur]].weight;
			ll nxt_dist = dst_dist[cur] + nxt_weight;
			pq.push({ nxt_weight, nxt_dist, nxt, cur });

			pos[cur]++;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i < MAX; i++)
	{
		srt_dist[i] = INF;
		dst_dist[i] = INF;
	}

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M;

		int u, v;
		ll w;

		for (int i = 0; i < M; i++)
		{
			cin >> u >> v >> w;
			G[u].push_back({ w, v });
			G[v].push_back({ w, u });
		}

		G[0].push_back({ 0,1 });

		for (int i = 1; i <= N; i++)
			sort(G[i].begin(), G[i].end());

		srtDijkstra();
		memset(pre, 0, sizeof(pre));
		memset(pos, 0, sizeof(pos));
		G[0][0] = { 0,N };
		dstDijkstra();

		ll ans = INF;

		for (int i = 1; i <= N; i++)
		{
			if (srt_dist[i] + dst_dist[i] < ans)
				ans = srt_dist[i] + dst_dist[i];
		}

		if (ans == INF)
			ans = -1;

		cout << "Case #" << test << "\n";
		cout << ans << "\n";

		init();
	}

	return 0;
}