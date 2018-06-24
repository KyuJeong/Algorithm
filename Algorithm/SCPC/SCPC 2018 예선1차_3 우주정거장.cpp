#include <bits/stdc++.h>

using namespace std;

#define MAX 200001

typedef vector <int> vi;

int T;
int N, M;
int deg[MAX];
bool include[MAX];
bool except[MAX];
vi G[MAX];
int cnt;

void Init()
{
	memset(deg, 0, sizeof(deg));
	memset(include, 0, sizeof(include));
	memset(except, 0, sizeof(except));
	for (int i = 1; i <= N; i++)
		G[i].clear();
	cnt = 0;
}

void Solve()
{
	queue <int> q;

	for (int i = 1; i <= N; i++)
	{
		if (deg[i] == 1)
		{
			include[i] = true;
			include[G[i][0]] = true;
		}
		if (deg[i] == 2)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (include[cur] || except[cur])
			continue;
		if (deg[cur] != 2)
			continue;

		int ptr = 0;
		int n[2];
		for (auto i : G[cur])
		{
			if (except[i])
				continue;
			n[ptr++] = i;
			if (ptr == 2)
				break;
		}

		if (ptr != 2)
			continue;

		int nxt, chk;
		if (G[n[0]].size() < G[n[1]].size())
		{
			nxt = n[0]; chk = n[1];
		}
		else
		{
			nxt = n[1]; chk = n[0];
		}

		bool cycle = false;
		for (auto i : G[nxt]) // 사이클 있는지 검사
		{
			if (i == chk)
			{
				cycle = true;
				break;
			}
		}
		if (cycle)
		{
			except[cur] = true;
			cnt++;
		}
		else
		{
			include[cur] = true;
			include[n[0]] = true;	include[n[1]] = true;
		}
		deg[n[0]]--; deg[n[1]]--;
		if (deg[n[0]] == 2)
			q.push(n[0]);
		if (deg[n[1]] == 2)
			q.push(n[1]);

	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			int from, to;
			cin >> from >> to;
			G[from].push_back(to);
			G[to].push_back(from);
			deg[from]++;
			deg[to]++;
		}

		Solve();

		int ans = N - cnt;

		cout << "Case #" << test << "\n";
		cout << ans << "\n";

		Init();
	}
}