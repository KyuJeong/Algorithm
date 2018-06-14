#include <bits/stdc++.h>

using namespace std;

int N, K;
int sec[100001];
int cnt[100001];

void BFS()
{
	queue <int> q;

	q.push(N);
	sec[N] = 0;
	cnt[N] = 1;

	int size;

	int second = 0;

	while (!q.empty())
	{
		size = q.size();

		for (int i = 0; i < size; i++)
		{
			int cur = q.front();
			q.pop();

			int nxt = cur - 1;
			if (nxt >= 0)
			{
				if (cnt[nxt] == 0)
				{
					sec[nxt] = second + 1;
					q.push(nxt);
				}
				if (sec[nxt] == second + 1)
					cnt[nxt] += cnt[cur];

			}

			nxt = cur + 1;
			if (nxt <= 100000)
			{
				if (cnt[nxt] == 0)
				{
					sec[nxt] = second + 1;
					q.push(nxt);
				}
				if (sec[nxt] == second + 1)
					cnt[nxt] += cnt[cur];
			}

			nxt = cur * 2;
			if (nxt <= 100000)
			{
				if (cnt[nxt] == 0)
				{
					sec[nxt] = second + 1;
					q.push(nxt);
				}
				if (sec[nxt] == second + 1)
					cnt[nxt] += cnt[cur];
			}
		}

		if (cnt[K] > 0)
			break;

		second++;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	BFS();

	cout << sec[K] << "\n" << cnt[K];

	return 0;
}