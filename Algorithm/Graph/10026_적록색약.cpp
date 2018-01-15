#include <iostream>
using namespace std;

char map[100][100];
int N;
int moveX[] = { 0,0,1,-1 };
int moveY[] = { 1,-1,0,0 };
bool check[100][100];
bool check_RB[100][100];
int area_count;
int area_count2;

void DFS_RGB(int y, int x, char clr)
{
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + moveY[i];
		int nx = x + moveX[i];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
		{
			if (!check[ny][nx] && map[ny][nx] == clr)
				DFS_RGB(ny, nx, clr);
		}
	}
}

void DFS_RB(int y, int x, char clr)
{
	check_RB[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + moveY[i];
		int nx = x + moveX[i];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N)
		{
			if (clr == 'R' || clr == 'G')
			{
				if (!check_RB[ny][nx] && (map[ny][nx] == 'R' || map[ny][nx] == 'G'))
					DFS_RB(ny, nx, clr);
			}
			else
			{
				if (!check_RB[ny][nx] && map[ny][nx] == clr)
					DFS_RB(ny, nx, clr);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1s", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				DFS_RGB(i, j, map[i][j]);
				area_count++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check_RB[i][j])
			{
				DFS_RB(i, j, map[i][j]);
				area_count2++;
			}
		}
	}

	printf("%d %d", area_count, area_count2);

	return 0;
}