#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y;
	int x;
	int cnt;
	int brk;
};

int n, m;
char G[1001][1001];
int chk[1001][1001][2];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

void bfs() {
	chk[0][0][0] = 1;
	chk[0][0][1] = 1;
	queue <Node> q;
	q.push({ 0,0,1,0 });

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + my[i];
			int nx = cur.x + mx[i];
			int nc = cur.cnt + 1;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (G[ny][nx] == '0') {
				if (chk[ny][nx][cur.brk] > nc || chk[ny][nx][cur.brk] == 0) {
					chk[ny][nx][cur.brk] = nc;
					q.push({ ny,nx,nc,cur.brk });
				}
			}
			else {
				if (cur.brk == 1) continue;
				else {
					if (chk[ny][nx][1] > nc || chk[ny][nx][1] == 0) {
						chk[ny][nx][1] = nc;
						q.push({ ny,nx,nc,1 });
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> G[i];

	bfs();
	int a = chk[n - 1][m - 1][0];
	int b = chk[n - 1][m - 1][1];
	if (a == 0) {
		if (b == 0) cout << "-1";
		else cout << b;
	}
	else {
		if (b == 0) cout << a;
		else cout << min(a, b);
	}

	return 0;
}