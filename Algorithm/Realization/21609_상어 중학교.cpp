#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y;
	int x;
};

struct Group {
	vector <Node> node;
	int cnt = 0;
	int rainbow_cnt = 0;
};

bool operator < (const Group& g1, const Group& g2) {
	if (g1.cnt == g2.cnt) {
		if (g1.rainbow_cnt == g2.rainbow_cnt) {
			if (g1.node[0].y == g2.node[0].y) {
				return g1.node[0].x > g2.node[0].x;
			}
			return g1.node[0].y > g2.node[0].y;
		}
		return g1.rainbow_cnt > g2.rainbow_cnt;
	}
	return g1.cnt > g2.cnt;
}

int n, m;
int G[21][21];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ans;
bool chk[21][21];

Group bfs(int y, int x) {
	queue <Node> q;
	Group ret;
	q.push({ y,x });
	chk[y][x] = true;
	int num = G[y][x];
	bool rainbow_chk[21][21] = { false };

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		ret.node.push_back({ cur.y,cur.x });
		ret.cnt++;
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (chk[ny][nx] || rainbow_chk[ny][nx] || (G[ny][nx] != 0 && G[ny][nx] != num)) continue;
			if (G[ny][nx] == 0) {
				rainbow_chk[ny][nx] = true;
				ret.rainbow_cnt++;
			}
			else {
				chk[ny][nx] = true;
			}
			q.push({ ny,nx });
		}
	}
	return ret;
}

bool remove_max_group() {
	memset(chk, false, sizeof(chk));
	vector <Group> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j] && G[i][j] > 0) {
				Group group = bfs(i, j);
				if (group.node.size() > 1) {
					v.push_back(group);
				}
			}
		}
	}
	if (v.size() == 0) return false;

	sort(v.begin(), v.end());

	ans += v[0].cnt * v[0].cnt;

	for (auto i : v[0].node)
		G[i.y][i.x] = -2;

	return true;
}

void set_gravity() {
	for (int x = 0; x < n; x++) {
		for (int y = n - 1; y >= 0; y--) {
			if (G[y][x] >= 0) {
				int ty = -1;
				for (int ny = y + 1; ny < n; ny++) {
					if (G[ny][x] != -2) break;
					ty = ny;
				}
				if (ty != -1) {
					G[ty][x] = G[y][x];
					G[y][x] = -2;
				}
			}
		}
	}

}

void rotate() {
	int T[21][21] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			T[i][j] = G[j][n - 1 - i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = T[i][j];
		}
	}
}

void solve() {
	while (remove_max_group()) {
		set_gravity();
		rotate();
		set_gravity();
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
		}
	}

	solve();

	cout << ans;

	return 0;
}