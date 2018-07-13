#include <bits/stdc++.h>

using namespace std;

int N, M;
vector <int> v[100001];
int w[100001];

void BFS()
{
	queue <int> q;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : v[cur])
		{
			w[next] += w[cur];
			q.push(next);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	int to, cost;
	cin >> to;
	for (int i = 2; i <= N; i++)
	{
		cin >> to;
		v[to].push_back(i);
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> to >> cost;
		w[to] += cost;
	}

	BFS();

	for (int i = 1; i <= N; i++)
		cout << w[i] << " ";

	return 0;
}