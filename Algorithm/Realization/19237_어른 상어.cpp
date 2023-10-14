#include <bits/stdc++.h>

using namespace std;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

struct NODE {
	int scent;
	int cnt;
};

struct POINT {
	int y;
	int x;
};

struct SHARK {
	POINT pt;
	int d;
};

struct PRIOR {
	int p[5][5];
};

int n, m, k;
NODE G[21][21];
NODE NG[21][21];
int dir[401];
PRIOR prior[401];
SHARK shark[401];
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };

void copy_graph() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			NG[y][x] = G[y][x];
			if (NG[y][x].cnt > 0) NG[y][x].cnt--;
			if (NG[y][x].cnt == 0) NG[y][x].scent = 0;
		}
	}
}

void re_copy_graph() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			G[y][x] = NG[y][x];
		}
	}
}

SHARK get_next(int num) {
	POINT cur = shark[num].pt;
	int cd = shark[num].d;
	for (int i = 1; i <= 4; i++) {
		int dir = prior[num].p[cd][i];
		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];
		if (ny < 1 || nx < 1 || ny > n || nx > n) continue;

		if (G[ny][nx].scent == 0) return{ ny,nx,dir };
	}

	for (int i = 1; i <= 4; i++) {
		int dir = prior[num].p[cd][i];
		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];
		if (ny < 1 || nx < 1 || ny > n || nx > n) continue;

		if (G[ny][nx].scent == num) return{ ny,nx,dir };
	}
}

int solve() {
	int move_cnt = 0;
	int shark_cnt = m;
	while (shark_cnt > 1) {
		move_cnt++;
		copy_graph();
		for (int i = 1; i <= m; i++) {
			if (shark[i].pt.y == -1) continue;
			SHARK nxt = get_next(i);
			if (NG[nxt.pt.y][nxt.pt.x].cnt == k) {
				shark[i] = { -1,-1 };
				shark_cnt--;
				continue;
			}
			shark[i] = nxt;
			NG[nxt.pt.y][nxt.pt.x] = { i, k };
		}
		re_copy_graph();
		if (move_cnt > 1000) return -1;
	}
	return move_cnt;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int num;
			cin >> num;
			G[y][x].scent = num;
			if (num != 0) {
				G[y][x].cnt = k;
				shark[num] = { y,x,0 };
			}
		}
	}

	for (int i = 1; i <= m; i++)
		cin >> shark[i].d;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 1; l <= 4; l++) {
				cin >> prior[i].p[j][l];
			}
		}
	}

	cout << solve();

	return 0;
}