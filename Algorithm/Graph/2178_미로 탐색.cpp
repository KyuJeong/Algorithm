#include <iostream>
#include <queue>

using namespace std;

struct Pt
{
	int y;
	int x;
	int cnt;

	Pt() {};
	Pt(int _y, int _x, int _cnt)
	{
		y = _y;	x = _x;	cnt = _cnt;
	}
};

int N, M;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,1,-1 };
int G[101][101];

int BFS()
{
	bool visit[101][101] = { false };

	queue <Pt> q;

	q.push({ 1,1,0 });

	int ret = 0;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cc = q.front().cnt;
		q.pop();
		if (cy == N && cx == M)
		{
			ret = cc;
			break;
		}
		if (visit[cy][cx])
			continue;
		visit[cy][cx] = true;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			int nc = cc + 1;

			if (ny < 1 || nx < 1 || ny > N || nx > M || visit[ny][nx])
				continue;
			if (G[ny][nx] == 0)
				continue;
			q.push({ ny,nx,nc });
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &G[i][j]);
		}
	}

	int ans = BFS() + 1;

	cout << ans;

	return 0;
}