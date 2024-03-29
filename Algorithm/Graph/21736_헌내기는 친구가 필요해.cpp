#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
char G[601][601];
bool chk[601][601];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int solve(int y, int x) {
	queue <Node> q;
	q.push({ y,x });

	chk[y][x] = true;

	int cnt = 0;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || chk[ny][nx]) continue;
			if (G[ny][nx] == 'X') continue;
			if (G[ny][nx] == 'P') cnt++;
			q.push({ ny,nx });
			chk[ny][nx] = true;
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> G[i];

	int ans;
	Node srt = { 0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 'I') {
				ans = solve(i, j);
				break;
			}
		}
	}

	if (ans == 0) cout << "TT";
	else cout << ans;

	return 0;
}