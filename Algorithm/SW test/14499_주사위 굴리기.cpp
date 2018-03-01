#include <iostream>
#include <algorithm>

using namespace std;

int N, M, cx, cy, K;
int c;

int G[21][21];
int my[] = { 0,0,0,-1,1 };
int mx[] = { 0,1,-1,0,0 };
int dice[6];

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &cy, &cx, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	int ny = cy;
	int nx = cx;

	while (K--)
	{
		scanf("%d", &c);

		ny = cy + my[c];
		nx = cx + mx[c];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;

		switch (c)
		{
			int tmp;
		case 1:
			tmp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[2];
			dice[2] = dice[5];
			dice[5] = tmp;
			break;
		case 2:
			tmp = dice[5];
			dice[5] = dice[2];
			dice[2] = dice[4];
			dice[4] = dice[0];
			dice[0] = tmp;
			break;
		case 3:
			tmp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = tmp;
			break;
		case 4:
			tmp = dice[3];
			dice[3] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[0];
			dice[0] = tmp;
			break;
		}

		if (G[ny][nx] == 0)
			G[ny][nx] = dice[2];
		else
		{
			dice[2] = G[ny][nx];
			G[ny][nx] = 0;
		}

		printf("%d\n", dice[0]);

		cy = ny;
		cx = nx;
	}

	return 0;
}