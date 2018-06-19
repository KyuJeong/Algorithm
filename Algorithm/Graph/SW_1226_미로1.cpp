#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int y;
	int x;

	Point() {}
	Point(int _y, int _x) :
		y(_y), x(_x) {}
};

int T;
int G[17][17];
bool visit[17][17];
Point src, dst;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

int BFS()
{
	queue <Point> q;

	q.push(src);

	visit[src.y][src.x] = true;

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();
		int cy = cur.y;
		int cx = cur.x;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			if (ny == dst.y && nx == dst.x)
				return 1;
			
			if (visit[ny][nx] || G[ny][nx] != 0)
				continue;
			if (ny < 1 || nx < 1 || ny > 16 || nx > 16)
				continue;
			
			q.push({ ny,nx });
			visit[ny][nx] = true;
		}
	}

	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int T = 10;

	while (T--)
	{
		int test;
		scanf("%d", &test);

		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				scanf("%1d", &G[i][j]);
				if (G[i][j] == 2)
					src = { i,j };
				if (G[i][j] == 3)
					dst = { i,j };
			}
		}

		int ans = BFS();

		cout << "#" << test << " " << ans << "\n";

		memset(G, 0, sizeof(G));
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}