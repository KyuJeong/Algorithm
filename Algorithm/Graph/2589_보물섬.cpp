#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Pt
{
	int y; int x; 
	int dist;
	Pt() {}
	Pt(int _y, int _x, int _dist)
	{
		y = _y;
		x = _x;
		dist = _dist;
	}
};

int N, M;
char G[50][50];
bool visit[50][50];
int my[] = { 0,0,-1,1 };
int mx[] = { 1,-1,0,0 };
int ans;

int BFS(Pt start)
{
	queue <Pt> q;

	visit[start.y][start.x] = true;

	q.push(start);

	int ret = 0;
	
	while (!q.empty())
	{
		Pt cur = q.front();
		int cy = cur.y;
		int cx = cur.x;
		int cd = cur.dist;
		q.pop();
		ret = max(ret, cd);

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			int nd = cd + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
				continue;
			if (G[ny][nx] == 'W')
				continue;

			q.push({ ny, nx, nd });
			visit[ny][nx] = true;
		}		
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (G[i][j] == 'L')
			{
				ans = max(ans, BFS({ i, j, 0 }));
				memset(visit, false, sizeof(visit));
			}
		}
	}

	cout << ans;

	return 0;
}