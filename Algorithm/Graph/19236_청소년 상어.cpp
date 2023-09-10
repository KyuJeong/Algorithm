#include <bits/stdc++.h>

using namespace std;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,-1,-1,-1,0,1,1,1 };

struct NODE {
	int num;
	int dir;
};

struct SHARK {
	int y;
	int x;
	int dir;
	int sum;
};

struct BOARD {
	NODE board[4][4];
	SHARK shark;
};

NODE srt[4][4];
SHARK s;

void init() {
	s = { 0,0,srt[0][0].dir };
	s.sum = srt[0][0].num;
	srt[0][0].num = -1;
}

void move_fish(int y, int x, NODE G[4][4]) {
	for (int i = 0; i < 8; i++) {
		int dir = (G[y][x].dir + i) % 8;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		if (G[ny][nx].num == -1) continue;
		G[y][x].dir = dir;

		if (G[ny][nx].num == 0) {
			G[ny][nx] = G[y][x];
			G[y][x].num = 0;
		}
		else {
			NODE tmp = G[ny][nx];
			G[ny][nx] = G[y][x];
			G[y][x] = tmp;
		}
		break;
	}
}

void move_board(NODE G[4][4]) {
	for (int idx = 1; idx <= 16; idx++) {
		bool find_chk = false;
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (G[y][x].num == idx) {
					move_fish(y, x, G);
					find_chk = true;
					break;
				}
			}
			if (find_chk) break;
		}
	}

}

int bfs() {
	queue <BOARD> q;
	BOARD cur;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cur.board[y][x] = srt[y][x];
		}
	}
	cur.shark = s;
	q.push(cur);
	int _max = 0;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		move_board(cur.board);

		for (int i = 0; i < 3; i++) {
			int ny = cur.shark.y;
			int nx = cur.shark.x;
			for (int cnt = 0; cnt <= i; cnt++) {
				ny += dy[cur.shark.dir];
				nx += dx[cur.shark.dir];
			}
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || cur.board[ny][nx].num == 0) {
				_max = max(_max, cur.shark.sum);
				continue;
			}
			BOARD nxt = cur;
			nxt.board[cur.shark.y][cur.shark.x].num = 0;
			nxt.board[ny][nx].num = -1;
			nxt.shark.y = ny;
			nxt.shark.x = nx;
			nxt.shark.dir = cur.board[ny][nx].dir;
			nxt.shark.sum += cur.board[ny][nx].num;
			q.push(nxt);
		}
	}
	return _max;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> srt[y][x].num >> srt[y][x].dir;
			srt[y][x].dir--;
		}
	}

	init();

	cout << bfs();

	return 0;
}