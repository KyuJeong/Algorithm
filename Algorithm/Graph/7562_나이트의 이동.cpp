#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Pt
{
	int y;
	int x;
	int dist;
	Pt() {};
	Pt(int _y, int _x, int _dist)
	{
		y = _y;
		x = _x;
		dist = _dist;
	}
};

int T, L;
bool visit[301][301];
Pt src, dst;
int my[] = { -1,-1,1,1,-2,-2,2,2 };
int mx[] = { -2,2,-2,2,-1,1,-1,1 };

int BFS(Pt start)
{
	queue <Pt> q;
	visit[start.y][start.x] = true;

	q.push(start);
	while (!q.empty())
	{
		Pt cur = q.front();
		int cy = cur.y;
		int cx = cur.x;
		int cd = cur.dist;
		q.pop();
		if (cy == dst.y && cx == dst.x)
			return cd;

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			int nd = cd + 1;
			if (visit[ny][nx])
				continue;
			if (ny < 0 || nx < 0 || ny >= L || nx >= L)
				continue;
			q.push({ ny,nx,nd });
			visit[ny][nx] = true;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		memset(visit, false, sizeof(visit));
		cin >> L;
		cin >> src.y >> src.x;
		cin >> dst.y >> dst.x;
		src.dist = 0;
		int ans = BFS(src);
		cout << ans << "\n";
	}

	return 0;
}