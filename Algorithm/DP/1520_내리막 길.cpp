#include <iostream>
#include <queue>

using namespace std;

struct Pt
{
	int y;
	int x;
	int cost;

	Pt() {}
	Pt(int _y, int _x, int _cost)
	{
		y = _y;
		x = _x;
		cost = _cost;
	}
};

bool operator < (const Pt &pt1, const Pt &pt2)
{
	return pt1.cost < pt2.cost;
}

int M, N;
int map[500][500];
int DP[500][500];
int moveY[] = { 0,0,1,-1 };
int moveX[] = { 1,-1,0,0 };
int main()
{
	std::ios::sync_with_stdio(false);

	priority_queue <Pt> pq;

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (i == 0 && j == 0)
				continue;
			pq.push(Pt(i, j, map[i][j]));
		}
	}

	DP[0][0] = 1;

	while (1)
	{
		Pt cur = pq.top();
		pq.pop();
		int y = cur.y;
		int x = cur.x;
		int cost = cur.cost;

		for (int i = 0; i < 4; i++)
		{
			int nY = y + moveY[i];
			int nX = x + moveX[i];

			if (nY < 0 || nX < 0 || nY >= M || nX >= N || map[y][x] >= map[nY][nX])
				continue;
			DP[y][x] += DP[nY][nX];
		}

		if (y == M - 1 && x == N - 1)
			break;
	}

	cout << DP[M - 1][N - 1];

	return 0;
}