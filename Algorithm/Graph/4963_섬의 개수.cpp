#include <iostream>

using namespace std;

struct Pt
{
	int x;
	int y;
};

int w, h;
bool map[50][50];
bool visit[50][50];
int mX[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int mY[8] = { 1, -1, 1, -1, -1, 1, 0, 0 };

void DFS(int _y, int _x)
{
	Pt nxt;
	nxt.x = _x;
	nxt.y = _y;
	visit[nxt.y][nxt.x] = true;

	for (int i = 0; i < 8; i++)
	{
		int nx = nxt.x + mX[i];
		int ny = nxt.y + mY[i];
		if (nx >= 0 && ny >= 0 && nx < w && ny < h && map[ny][nx] && !visit[ny][nx])
		{
			DFS(ny, nx);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	while (1)
	{
		cin >> w >> h;
		if (w == 0)
			break;
		int countIsland = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					DFS(i, j);
					countIsland++;
				}
			}
		}
		cout << countIsland << "\n";
	}

	return 0;
}