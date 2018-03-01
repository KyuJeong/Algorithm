#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Pt
{
	int y;
	int x;
	int sum;
	int cnt;

	Pt() {};
	Pt(int _y, int _x, int _sum, int _cnt)
	{
		y = _y;
		x = _x;
		sum = _sum;
		cnt = _cnt;
	}
};

int N, M;
int G[501][501];
int ans;
int my[] = { 0,1,0,-1 };
int mx[] = { -1,0,1,0 };
bool check[501][501];

void DFS(Pt pt)
{
	Pt cur = pt;
	int cy = cur.y;
	int cx = cur.x;
	int cs = cur.sum;
	int cc = cur.cnt;

	check[cy][cx] = true;

	for (int i = 0; i < 3; i++)
	{
		int ny = cy + my[i];
		int nx = cx + mx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (check[ny][nx])
			continue;

		int ns = cs + G[ny][nx];
		int nc = cc + 1;

		if (nc == 4)
			ans = max(ans, ns);
		else
			DFS(Pt({ ny,nx,ns,nc }));
	}

	check[cy][cx] = false;	
}

void Except(Pt pt)
{
	Pt cur = pt;
	int cy = cur.y;
	int cx = cur.x;
	int cs = cur.sum;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				int ny[] = { cy + my[i], cy + my[j], cy + my[k] };
				int nx[] = { cx + mx[i], cx + mx[j], cx + mx[k] };
				int ns = cs;
				for (int m = 0; m < 3; m++)
				{
					if (ny[m] < 0 || nx[m] < 0 || ny[m] >= N || nx[m] >= M)
					{
						ns = -1;
						break;
					}
					ns += G[ny[m]][nx[m]];
				}
				ans = max(ans, ns);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DFS(Pt{ i,j,G[i][j],1 });
			memset(check, false, sizeof(check));
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Except(Pt{ i,j,G[i][j],1 });
		}
	}

	cout << ans;

	return 0;
}