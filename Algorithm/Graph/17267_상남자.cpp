#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int y, x, lc, rc;
	Node() {}
	Node(int _y, int _x, int _lc, int _rc) : y(_y), x(_x), lc(_lc), rc(_rc) {}
};

int n, m, l, r;
char G[1001][1001];
bool visit[1001][1001];
int my[] = { -1,1 };
int mx[] = { -1,1 };
int al[] = { 1,0 };
int ar[] = { 0,1 };

int bfs(int sy, int sx)
{
	int ret = 1;
	queue <Node> q;
	q.push({ sy,sx,0,0 });
	visit[sy][sx] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int ny = cur.y;
			while (1)
			{
				ny += my[i];
				if (ny < 0 || ny >= n || G[ny][cur.x] == '1')
					break;
				if (!visit[ny][cur.x])
				{
					ret++;
					visit[ny][cur.x] = true;
					q.push({ ny,cur.x,cur.lc,cur.rc });
				}
			}
		}
		for (int j = 0; j < 2; j++)
		{
			int nx = cur.x + mx[j];
			int nl = cur.lc + al[j];
			int nr = cur.rc + ar[j];
			if (nx < 0 || nx >= m || G[cur.y][nx] == '1' || nl > l || nr > r)
				continue;
			if (!visit[cur.y][nx])
			{
				visit[cur.y][nx] = true;
				q.push({ cur.y,nx,nl,nr });
				ret++;
			}
		}
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> l >> r;
	int sy, sx;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '2')
			{
				sy = i; sx = j;
			}
		}
	}

	int ans = bfs(sy, sx);
	cout << ans;

	return 0;
}