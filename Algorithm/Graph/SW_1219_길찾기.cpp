#include <bits/stdc++.h>

using namespace std;


bool visit[101];
int from, to;

int BFS(vector <int> G[101])
{
	queue <int> q;

	q.push(0);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : G[cur])
		{
			if (i == 99)
				return 1;

			if (visit[i])
				continue;

			visit[i] = true;
			q.push(i);
		}
	}

	return 0;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int test;
	while (cin >> test)
	{
		int M;
		cin >> M;
		vector <int> G[101];

		for (int i = 0; i < M; i++)
		{
			cin >> from >> to;
			G[from].push_back(to);
		}

		int ans = BFS(G);

		memset(visit, 0, sizeof(visit));

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}