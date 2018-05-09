#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int N, M;
vi v[100001];
vi r[100001];
int from, to;
bool visit_v[100001];
bool visit_r[100001];
int T;

void BFS_V()
{
	queue <int> q;
	q.push(1);
	visit_v[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : v[cur])
		{
			if (visit_v[i])
				continue;
			visit_v[i] = true;
			q.push(i);
		}
	}
}

void BFS_R()
{
	queue <int> q;
	q.push(N);
	visit_r[N] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : r[cur])
		{
			if (visit_r[i])
				continue;
			visit_r[i] = true;
			q.push(i);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		r[to].push_back(from);
	}

	BFS_V();
	BFS_R();

	cin >> T;

	while (T--)
	{
		int vtx;
		cin >> vtx;

		if (visit_v[vtx] && visit_r[vtx])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}

	return 0;
}