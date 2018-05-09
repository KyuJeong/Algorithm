#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

typedef vector <int> vi;
typedef pair <int, int> pii;

int N, M, J, K;
vector <pii> v[5001];
vi A, B;
int f, t, c;
int dist[5001];
bool visit[5001];

void Dijkstra()
{
	priority_queue <pii> pq;

	pq.push({ 0,J });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_dist = -pq.top().first;
		pq.pop();

		if (visit[cur])
			continue;
		visit[cur] = true;

		for (auto i : v[cur])
		{
			int nxt = i.second;
			int nxt_dist = i.first;
			if (dist[nxt] > cur_dist + nxt_dist)
			{
				dist[nxt] = cur_dist + nxt_dist;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> J >> K;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	dist[J] = 0;

	int tmp;
	for (int i = 0; i < K; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	
	for (int i = 0; i < K; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> f >> t >> c;
		v[f].push_back({ c,t });
		v[t].push_back({ c,f });
	}

	Dijkstra();

	dist[J] = INF;

	int min_A = 1e9;
	int min_B = 1e9;
	for (auto i : A)
	{
		min_A = min(min_A, dist[i]);
	}

	for (auto i : B)
	{
		min_B = min(min_B, dist[i]);
	}

	if (min_A == min_B)
	{
		if (min_A == 1e9)
			cout << "-1";
		else
		{
			cout << "A\n";
			cout << min_A;
		}
	}
	else
	{
		if (min_A < min_B)
		{
			cout << "A\n";
			cout << min_A;
		}
		else
		{
			cout << "B\n";
			cout << min_B;
		}
	}

	return 0;
}