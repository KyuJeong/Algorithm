#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 100

struct Pt
{
	int y, x;
	Pt() {};
	Pt(int _y, int _x)
	{
		y = _y; x = _x;
	}
};

int N;
int G[MAX][MAX];
bool visit[MAX][MAX];
int idx[MAX][MAX];
int my[] = { 0,0,1,-1 };
int mx[] = { 1,-1,0,0 };
int ans;

void init(int row, int col, int num)
{
	queue <Pt> q;
	q.push({ row,col });

	visit[row][col] = true;

	while (!q.empty())
	{
		Pt cur = q.front();
		q.pop();
		int cy = cur.y;
		int cx = cur.x;

		idx[cy][cx] = num;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
				continue;

			if (G[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int BFS(int row, int col, int cnt)
{
	int cy = row;
	int cx = col;
	visit[cy][cx] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = cy + my[i];
		int nx = cx + mx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
			continue;

		if (!G[ny][nx])
		{
			G[ny][nx] = cnt;
			idx[ny][nx] = idx[cy][cx];
		}

		else if (idx[ny][nx] != idx[cy][cx])
		{
			if (G[ny][nx] > G[cy][cx])
				return cnt - 2;
			else
				return cnt - 3;
		}

	}
	return 1e9;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
		}
	}

	int tmp = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && G[i][j])
			{
				init(i, j, tmp);
				tmp++;
			}
		}
	}

	memset(visit, false, sizeof(visit));

	int cnt = 1;
	tmp = 1e9;
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j] && G[i][j] == cnt)
				{
					tmp = min(tmp, BFS(i, j, cnt + 2));
				}
			}
		}
		if (tmp != 1e9)
		{
			ans = tmp;
			break;
		}
		cnt += 2;
	}

	cout << ans;

	return 0;
}