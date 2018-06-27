#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N, M;
int G[101][101];
int dist[101][101];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

void BFS()
{
	deque <pii> dq;
	dq.push_back({ 1,1 });
	dist[1][1] = 0;

	while (!dq.empty())
	{
		int cy = dq.front().first;
		int cx = dq.front().second;
		int cur_dist = dist[cy][cx];
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];

			if (ny < 1 || nx < 1 || ny > N || nx > M)
				continue;
			if (dist[ny][nx] != -1)
				continue;

			if (G[ny][nx] == 0)
			{
				dist[ny][nx] = cur_dist;
				dq.push_front({ ny,nx });
			}
			else
			{
				dist[ny][nx] = cur_dist + 1;
				dq.push_back({ ny,nx });
			}

			if (ny == N && nx == M)
				return;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf("%1d", &G[i][j]);
	}

	memset(dist, -1, sizeof(dist));

	BFS();

	cout << dist[N][M];

	return 0;
}