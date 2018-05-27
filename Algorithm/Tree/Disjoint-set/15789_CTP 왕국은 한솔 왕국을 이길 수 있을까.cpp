#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

vector <int> v[100001];
int parent[100001];
bool visit[100001];
int child_count[100001];
priority_queue <pii> pq;
int C, H, P;

int Find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = Find(parent[u]);
}

void Merge(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
		return;
	parent[u] = v;
}

void BFS(int a)
{
	queue <int> q;
	int srt = parent[a];
	q.push(srt);
	visit[srt] = true;

	while (!q.empty())
	{
		int cur = q.front();
		child_count[srt]++;
		q.pop();

		for (auto nxt : v[cur])
		{
			if (!visit[nxt])
			{
				q.push(nxt);
				visit[nxt] = true;
			}
		}
	}

	if (srt != parent[C] && srt != parent[H])
		pq.push({ child_count[srt], srt });
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int from, to;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		Merge(to, from);

		v[from].push_back(to);
		v[to].push_back(from);
	}

	cin >> C >> H >> P;

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			BFS(i);
		}
	}

	int C_pow = child_count[parent[C]];
	int H_pow = child_count[parent[H]];

	for (int i = 0; i < P; i++)
	{
		if (pq.empty())
			break;
		pii top = pq.top();
		pq.pop();
		int num = top.first;
		int idx = top.second;
		C_pow += num;
	}

	cout << C_pow;


	return 0;
}