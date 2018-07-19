#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N;
int u, v;
vector <int> G[MAX];
int parent[MAX];
bool visit[MAX];

void bfs()
{
	queue <int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			if (visit[i])
				continue;

			parent[i] = cur;
			visit[i] = true;
			q.push(i);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}