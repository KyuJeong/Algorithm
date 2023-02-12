#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[25][25];
bool visit[25][25];
int moveY[] = { 0,0,1,-1 };
int moveX[] = { 1,-1,0,0 };
int idx;
int house_count[625];

struct Pt
{ 
	int y;
	int x;
	Pt()
	{}
	Pt(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

void BFS(int _y, int _x)
{
	queue <Pt> que;	// 좌표 구조체

	que.push(Pt(_y, _x));

	visit[_y][_x] = true;	// 방문했던 곳 체크

	while (!que.empty())
	{
		Pt cur = que.front();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + moveY[i];	// moveY = { 0,0,1,-1 } (상하좌우 검사)
			int nx = cur.x + moveX[i];	// moveX = { 1,-1,0,0 } 
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx])
				continue;
			if (map[ny][nx] == 1)
			{
				que.push(Pt(ny, nx));
				visit[ny][nx] = true;
				house_count[idx]++;
			}
		}
		que.pop();
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				BFS(i, j);
				idx++;
			}
		}
	}

	sort(house_count, house_count + idx);

	printf("%d\n", idx);

	for (int i = 0; i < idx; i++)
	{
		printf("%d\n", house_count[i] + 1);
	}

	return 0;
}