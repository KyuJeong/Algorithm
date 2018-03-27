#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair <int, int> pii;

int T;
int G[51][51];
bool visit[51][51];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
int N, M, K;

void BFS(int y, int x)
{
	queue <pii> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (visit[cy][cx])
			continue;
		visit[cy][cx] = true;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			if(ny < 0 || nx < 0 || ny > N || nx > M || visit[ny][nx])
				continue;
			if (G[ny][nx] == 0)
				continue;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		int y, x;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			G[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && G[i][j] == 1)
				{
					BFS(i, j);
					cnt++;
				}
			}
		}

		memset(G, 0, sizeof(G));
		memset(visit, false, sizeof(visit));

		cout << cnt << "\n";
	}

	return 0;
}