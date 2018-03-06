#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> pii;
typedef pair <int, char> pic;

int N, K;
int G[101][101];
int row, col;
int L;
int X;
char C;
int my[] = { 0,1,0,-1 };
int mx[] = { 1,0,-1,0 };
vector <pic> v;

int Move()
{
	int sec = 0;
	int cy = 1;
	int cx = 1;
	int dir = 0;
	int idx = 0;

	queue <pii> tail;
	tail.push({ 1,1 });

	while (1)
	{
		if (sec == v[idx].first) // 방향전환
		{
			if (v[idx].second == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			idx++;
		}

		sec++;

		int ny = cy + my[dir];
		int nx = cx + mx[dir];
		if (ny == 0 || nx == 0 || ny > N || nx > N)
			break;
		if (G[ny][nx] == 2)
			break;

		if (G[ny][nx] == 1)
			tail.push({ ny,nx });
		else
		{
			tail.push({ ny,nx });
			int ty = tail.front().first;
			int tx = tail.front().second;
			G[ty][tx] = 0;
			if(tail.size() > 1)
				tail.pop();
		}

		G[ny][nx] = 2;

		cy = ny;
		cx = nx;
	}

	return sec;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> row >> col;
		G[row][col] = 1;
	}

	G[1][1] = 2;

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		v.push_back({ X,C });
	}

	v.push_back({ -1,'\n' }); // 오버플로우 방지

	cout << Move();

	return 0;
}