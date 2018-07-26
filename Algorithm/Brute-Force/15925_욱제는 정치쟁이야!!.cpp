#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N, M;
int G[32][32];
int cnt[2][32];

void solve()
{
	int m = N / 2;
	queue <pii> q;
	for (int i = 0; i < N; i++)
	{
		if (cnt[0][i] > m) q.push({ 0,i });
		if (cnt[1][i] > m) q.push({ 1,i });
	}

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		int dir = cur.first;
		int idx = cur.second;
		if (cnt[dir][idx] == N) continue;

		for (int i = 0; i < N; i++)
		{
			if (dir == 0)
			{
				if (G[idx][i] != M)
				{
					G[idx][i] = M;
					if (++cnt[1][i] > m)
						q.push({ 1, i });
				}
			}
			else
			{
				if (G[i][idx] != M)
				{
					G[i][idx] = M;
					if (++cnt[0][i] > m)
						q.push({ 0, i });
				}
			}
		}
		cnt[dir][idx] = N;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == M)
				cnt[0][i]++, cnt[1][j]++;
		}
	}

	solve();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (G[i][j] != M)
			{
				cout << "0";
				return 0;
			}
		}
	}

	cout << "1";

	return 0;
}