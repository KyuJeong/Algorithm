#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

struct Pt
{
	int y; int x;
	Pt() {};
	Pt(int _y, int _x) : y(_y), x(_x) {};
};

int n;
int g[MAXN][MAXN];
bool visit[MAXN][MAXN];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,1,-1 };
int h;

void bfs(int y, int x)
{
	queue <Pt> q;
	q.push({ y,x });

	while (!q.empty())
	{
		Pt cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + my[i];
			int nx = cur.x + mx[i];
			if (ny < 1 || nx < 1 || ny > n || nx > n || visit[ny][nx])
				continue;
			if (g[ny][nx] <= h) continue;
			if (!visit[ny][nx])
				q.push({ ny,nx });
			visit[ny][nx] = true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];

	int _max = 0;
	for (h = 0; h <= 100; h++)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!visit[i][j] && g[i][j] > h)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0) break;
		memset(visit, 0, sizeof(visit));
		_max = max(_max, cnt);
	}

	cout << _max;

	return 0;
}