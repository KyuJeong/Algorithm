#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pt
{
	int x;
	int y;
	int height = 0;
};

int map[1000][1000];
int H, W, N;
queue<Pt> que;
Pt start;
string temp;
int goal;
int moveCount;
int totalMoveCount;
bool findPath;
int moveX[4] = { 0,0, 1, -1 };
int moveY[4] = { 1,-1, 0, 0 };

void setQue(int _x, int _y, int _height)
{
	if (map[_x][_y] == goal)
	{
		start.x = _x;
		start.y = _y;
		findPath = true;
		moveCount = _height + 1;
		return;
	}
	Pt next;
	next.x = _x;
	next.y = _y;
	next.height = _height + 1;
	que.push(next);
	findPath = false;
}

void BFS(Pt _start)
{
	goal++;
	bool visit[1000][1000] = { false };
	while (!que.empty())
		que.pop();
	que.push(_start);
	visit[_start.x][_start.y] = true;

	while (!que.empty())
	{
		Pt front = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = front.x + moveX[i];
			int ny = front.y + moveY[i];
			if (ny >= 0 && nx >= 0 && ny < W && nx < H && !visit[nx][ny] && map[nx][ny] != -1)
			{
				setQue(nx, ny, front.height);
				visit[nx][ny] = true;
				if (findPath) break;
			}
		}

		if (findPath)
		{
			totalMoveCount += moveCount;
			return;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> H >> W >> N;

	for (int i = 0; i < H; i++)
	{
		cin >> temp;
		for (int j = 0; j < W; j++)
		{
			if (temp[j] == 46)	map[i][j] = 0;
			else if (temp[j] == 'X') map[i][j] = -1;
			else if (temp[j] == 'S')
			{
				start.x = i;
				start.y = j;
			}
			else
			{
				map[i][j] = temp[j] - 48;
			}
		}
	}

	while (N--)
		BFS(start);

	cout << totalMoveCount;

	return 0;
}