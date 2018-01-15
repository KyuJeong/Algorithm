#include <iostream>
#include <queue>
using namespace std;

int H, W;
char map[1500][1500];
bool visit[1500][1500];
bool swan_visit[1500][1500];
int swan_num[1500][1500];
int moveY[] = { 0,0,1,-1 };
int moveX[] = { 1,-1,0,0 };
int count_day;
queue <pair <int, int>> swan_next[2];
bool second_swan;

void BFS_ice()
{
	queue <pair <int, int>> que;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (!visit[i][j] && (map[i][j] == '.' || map[i][j] == 'L'))
			{
				que.push(make_pair(i, j));
				visit[i][j] = true;
			}

		}
	}

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + moveY[i];
			int nx = x + moveX[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W || visit[ny][nx])
				continue;
			if (map[ny][nx] == 'X')
				map[ny][nx] = '.';
		}
	}
}

bool BFS_swan()
{
	queue < pair <int, int>> que;

	for (int i = 0; i < 2; i++)
	{
		que = swan_next[i];

		while (!swan_next[i].empty())
			swan_next[i].pop();

		while (!que.empty())
		{
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			swan_visit[y][x] = true;
			swan_num[y][x] = i + 1;

			int find_swan;

			if (i == 0)
				find_swan = 2;
			else
				find_swan = 1;

			for (int j = 0; j < 4; j++)
			{
				int ny = y + moveY[j];
				int nx = x + moveX[j];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
				if (swan_num[ny][nx] == find_swan && map[ny][nx] == '.')
					return true;
				if (swan_visit[ny][nx])	continue;

				if (map[ny][nx] == '.')
					que.push(make_pair(ny, nx));
				else if (map[ny][nx] == 'X')
				{
					swan_next[i].push(make_pair(ny, nx));
					swan_num[ny][nx] = i + 1;
				}
				else if (map[ny][nx] == 'L')
					return true;

				swan_visit[ny][nx] = true;
			}
		}
	}

	return false;

}

int main()
{
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'L')
			{
				if (!second_swan)
				{
					swan_next[0].push(make_pair(i, j));
					second_swan = true;
				}
				else
					swan_next[1].push(make_pair(i, j));
			}
		}
	}

	while (!BFS_swan())
	{
		BFS_ice();

		count_day++;
	}

	cout << count_day;

	return 0;
}