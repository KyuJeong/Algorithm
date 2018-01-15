#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
int G[101][101];
bool visit[101][101];
int my[] = { 0,0,-1,1 };
int mx[] = { 1,-1,0,0 };
int X1, X2, Y1, Y2;
int cnt;
int cur_area;
int area[5001];

struct Pt {
	int y;
	int x;
	Pt() {};
	Pt(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

int BFS(Pt pt)
{
	visit[pt.y][pt.x] = true;

	int my_area = 1;

	queue <Pt> q;

	q.push(pt);

	while (!q.empty())
	{
		Pt cur = q.front();
		q.pop();
		int cy = cur.y;
		int cx = cur.x;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N || visit[ny][nx])
				continue;
			
			if (!G[ny][nx])
			{
				q.push(Pt(ny, nx));
				visit[ny][nx] = true;
				my_area++;
			}
		}
	}

	return my_area;
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		for (int j = Y1; j < Y2; j++)
		{
			for (int k = X1; k < X2; k++)
			{
				G[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && !G[i][j])
			{
				area[cnt] = BFS(Pt(i, j));
				cnt++;
			}
		}
	}

	sort(area, area + cnt);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", area[i]);
	}
	
	return 0;
}