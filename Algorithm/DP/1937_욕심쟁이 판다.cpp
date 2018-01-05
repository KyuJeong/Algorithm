#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

int n;
int G[501][501];
int DP[501][501];
priority_queue <Pt> pq;
int moveY[] = { 0,0,-1,1 };
int moveX[] = { 1,-1,0,0 };
int ans;

bool operator< (const Pt &pt1, const Pt &pt2)
{
	return pt1.cost < pt2.cost;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> G[i][j];
			pq.push(Pt(i, j, G[i][j]));
			DP[i][j] = 0;
		}
	}

	while (!pq.empty())
	{
		Pt cur = pq.top();
		pq.pop();

		int cy = cur.y;
		int cx = cur.x;
		int cc = cur.cost;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + moveY[i];
			int nx = cx + moveX[i];
			if (G[cy][cx] >= G[ny][nx])
				continue;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			DP[cy][cx] = max(DP[cy][cx], DP[ny][nx]);
		}
		DP[cy][cx] += 1;
		ans = max(DP[cy][cx], ans);
	}

	cout << ans;

	return 0;
}