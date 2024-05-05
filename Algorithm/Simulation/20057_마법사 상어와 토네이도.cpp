#include <bits/stdc++.h>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int n;
int G[501][501];
int out_sand;

int move_sand(int y, int x, int sand) {
	if (y < 0 || x < 0 || y >= n || x >= n) out_sand += sand;
	else G[y][x] += sand;
	return sand;
}

void move_tornado(int y, int x, int dir) {
	if (dir == 0) {
		int sand = G[y - 1][x];
		int moved_sand = 0;
		moved_sand += move_sand(y - 3, x, sand * 5 / 100);
		moved_sand += move_sand(y - 2, x - 1, sand * 10 / 100);
		moved_sand += move_sand(y - 2, x + 1, sand * 10 / 100);
		moved_sand += move_sand(y - 1, x - 2, sand * 2 / 100);
		moved_sand += move_sand(y - 1, x + 2, sand * 2 / 100);
		moved_sand += move_sand(y - 1, x - 1, sand * 7 / 100);
		moved_sand += move_sand(y - 1, x + 1, sand * 7 / 100);
		moved_sand += move_sand(y, x - 1, sand * 1 / 100);
		moved_sand += move_sand(y, x + 1, sand * 1 / 100);
		move_sand(y - 2, x, sand - moved_sand);
		G[y - 1][x] = 0;
	}
	else if (dir == 1) {
		int sand = G[y + 1][x];
		int moved_sand = 0;
		moved_sand += move_sand(y + 3, x, sand * 5 / 100);
		moved_sand += move_sand(y + 2, x - 1, sand * 10 / 100);
		moved_sand += move_sand(y + 2, x + 1, sand * 10 / 100);
		moved_sand += move_sand(y + 1, x - 2, sand * 2 / 100);
		moved_sand += move_sand(y + 1, x + 2, sand * 2 / 100);
		moved_sand += move_sand(y + 1, x - 1, sand * 7 / 100);
		moved_sand += move_sand(y + 1, x + 1, sand * 7 / 100);
		moved_sand += move_sand(y, x - 1, sand * 1 / 100);
		moved_sand += move_sand(y, x + 1, sand * 1 / 100);
		move_sand(y + 2, x, sand - moved_sand);
		G[y + 1][x] = 0;
	}
	else if (dir == 2) {
		int sand = G[y][x - 1];
		int moved_sand = 0;
		moved_sand += move_sand(y, x - 3, sand * 5 / 100);
		moved_sand += move_sand(y - 1, x - 2, sand * 10 / 100);
		moved_sand += move_sand(y + 1, x - 2, sand * 10 / 100);
		moved_sand += move_sand(y - 2, x - 1, sand * 2 / 100);
		moved_sand += move_sand(y + 2, x - 1, sand * 2 / 100);
		moved_sand += move_sand(y - 1, x - 1, sand * 7 / 100);
		moved_sand += move_sand(y + 1, x - 1, sand * 7 / 100);
		moved_sand += move_sand(y - 1, x, sand * 1 / 100);
		moved_sand += move_sand(y + 1, x, sand * 1 / 100);
		move_sand(y, x - 2, sand - moved_sand);
		G[y][x - 1] = 0;
	}
	else if (dir == 3) {
		int sand = G[y][x + 1];
		int moved_sand = 0;
		moved_sand += move_sand(y, x + 3, sand * 5 / 100);
		moved_sand += move_sand(y - 1, x + 2, sand * 10 / 100);
		moved_sand += move_sand(y + 1, x + 2, sand * 10 / 100);
		moved_sand += move_sand(y - 2, x + 1, sand * 2 / 100);
		moved_sand += move_sand(y + 2, x + 1, sand * 2 / 100);
		moved_sand += move_sand(y - 1, x + 1, sand * 7 / 100);
		moved_sand += move_sand(y + 1, x + 1, sand * 7 / 100);
		moved_sand += move_sand(y - 1, x, sand * 1 / 100);
		moved_sand += move_sand(y + 1, x, sand * 1 / 100);
		move_sand(y, x + 2, sand - moved_sand);
		G[y][x + 1] = 0;
	}
}

void solve() {
	int cy = n / 2;
	int cx = n / 2;
	int dir = 2;
	int lmt = 1;
	int cnt = 0;

	while (1) {
		if (cy == 0 && cx == 0) break;
		move_tornado(cy, cx, dir);
		cnt++;
		cy += dy[dir];
		cx += dx[dir];
		if (cnt == lmt) {
			cnt = 0;
			if (dir == 0) {
				dir = 2;
				lmt++;
			}
			else if (dir == 1) {
				dir = 3;
				lmt++;
			}
			else if (dir == 2) {
				dir = 1;
			}
			else if (dir == 3) {
				dir = 0;
			}
		}

	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
		}
	}

	solve();

	cout << out_sand;

	return 0;
}