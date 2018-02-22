#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Pt
{
	int y;
	int x;
	Pt();
	Pt(int _y, int _x)
	{
		y = _y;
		x = _x;
	};
};

int N, M;
int G[8][8];
int map_size;
int wall_cnt;
int ans;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

void MakeWall(int, int);
int BFS();
queue <Pt> SearchVirus();

/* 벽을 세워서 검사하고 다시 없앰 */
void MakeWall(int a, int b)
{
	int src = a * M + b;

	G[a][b] = 1;

	for (int i = src + 1; i < N * M - 1; i++)
	{
		if (G[i / M][i % M] == 0)
		{
			G[i / M][i % M] = 1;
			for (int j = i + 1; j < N * M; j++)
			{
				if (G[j / M][j % M] == 0)
				{
					G[j / M][j % M] = 1;

					ans = max(ans, BFS());

					G[j / M][j % M] = 0;
				}
			}
			G[i / M][i % M] = 0;
		}
	}

	G[a][b] = 0;

}

/* 안전 영역 갯수 계산 */
int BFS()
{
	bool visit[8][8] = { false };

	queue <Pt> q = SearchVirus();

	int cnt = q.size();

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		visit[cy][cx] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + my[i];
			int nx = cx + mx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])
				continue;
			if (G[ny][nx] == 0)
			{
				visit[ny][nx] = true;
				cnt++;
				q.push(Pt{ ny,nx });
			}
		}
	}

	int safe = map_size - wall_cnt - cnt;
	return safe;
}

/* 바이러스가 있는 위치 구하는 함수 */
queue <Pt> SearchVirus()
{
	queue <Pt> que;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (G[i][j] == 2)
				que.push(Pt{ i,j });
		}
	}
	return que;
}


int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	map_size = N * M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 1)
				wall_cnt++;
		}
	}

	wall_cnt += 3;

	for (int i = 0; i < N * M - 2; i++)
	{
		if (G[i / M][i % M] == 0)
			MakeWall(i / M, i % M);
	}

	cout << ans;

	return 0;
}