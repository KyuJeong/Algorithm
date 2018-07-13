#include <bits/stdc++.h>

using namespace std;

int N, M;
vector <int> v[100001];
int w[100001];

void BFS(int x, int c)
{
	queue <int> q;
	q.push(x);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : v[cur])
		{
			w[next] += c;
			q.push(next);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	int q, to, cost;
	cin >> to;
	for (int i = 2; i <= N; i++)
	{
		cin >> to;
		v[to].push_back(i);
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> to >> cost;
			w[to] += cost;
			BFS(to, cost);
		}
		else
		{
			cin >> to;
			cout << w[to] << "\n";
		}
	}

	return 0;
}