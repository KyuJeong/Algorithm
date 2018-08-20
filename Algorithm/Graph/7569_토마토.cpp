#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

struct Pt
{
	int y; int x; int z;
	Pt() {};
	Pt(int _y, int _x, int _z) : y(_y), x(_x), z(_z) {};
};

int g[MAXN][MAXN][MAXN];
bool visit[MAXN][MAXN][MAXN];
int n, m, h;
int my[] = { 1,-1,0,0,0,0 };
int mx[] = { 0,0,1,-1,0,0 };
int mz[] = { 0,0,0,0,1,-1 };
int zero;

int bfs()
{
	queue <Pt> q;

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
				if (g[j][k][i] == 1)
					q.push({ j,k,i });

	int sz = q.size();
	int day = 0;
	int chg = 0;
	while (!q.empty())
	{
		day++;
		while (sz--)
		{
			Pt cur = q.front();
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int ny = cur.y + my[i];
				int nx = cur.x + mx[i];
				int nz = cur.z + mz[i];

				if (ny < 1 || ny > n || nx < 1 || nx > m || nz < 1 || nz > h)
					continue;
				if (visit[ny][nx][nz]) continue;
				if (g[ny][nx][nz] == -1) continue;

				q.push({ ny,nx,nz });
				if (g[ny][nx][nz] == 0)
				{
					chg++;
					g[ny][nx][nz] = 1;
				}
				g[ny][nx][nz] = 1;
				visit[ny][nx][nz] = true;
			}
		}
		if (chg == zero) break;
		sz = q.size();
	}
	if (chg != zero) return -1;
	return day;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> m >> n >> h;

	int cnt[3] = { 0 };
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				cin >> g[j][k][i];
				if (g[j][k][i] == 0) zero++;
			}
		}
	}

	int ans;
	if (zero == 0)
		ans = 0;
	else
		ans = bfs();

	cout << ans;

	return 0;
}