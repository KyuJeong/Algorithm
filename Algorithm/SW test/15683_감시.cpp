#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y;
	int x;
	int num;
};

int n, m;
int G[9][9];
vector <Node> v;
int my[] = { -1,0,1,0 };
int mx[] = { 0,1,0,-1 };
int side, sz, ans;

inline void solve() {
	bool visit[9][9] = { false };
	int cnt = 0;
	for (auto& cur : v) {
		for (int i = 0; i < 4; i++) {
			int ny = cur.y;
			int nx = cur.x;
			if ((1 << i) & G[ny][nx]) {
				while (1) {
					ny += my[i];
					nx += mx[i];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m || G[ny][nx] == -1) break;
					if (!visit[ny][nx] && G[ny][nx] == 0) cnt++;
					visit[ny][nx] = true;
				}
			}
		}
	}
	ans = min(ans, side - cnt);
}

inline void rotate(int idx) {
	if (idx == sz) {
		solve();
		return;
	}
	int y = v[idx].y;
	int x = v[idx].x;
	switch (v[idx].num) {
	case 1:
		G[y][x] = 1;
		rotate(idx + 1);
		for (int i = 0; i < 3; i++) {
			G[y][x] <<= 1;
			rotate(idx + 1);
		}
		break;
	case 2:
		G[y][x] = 5;
		rotate(idx + 1);
		G[y][x] = 10;
		rotate(idx + 1);
		break;
	case 3:
		G[y][x] = 25;
		rotate(idx + 1);
		for (int i = 0; i < 3; i++) {
			G[y][x] >>= 1;
			rotate(idx + 1);
		}
		break;
	case 4:
		G[y][x] = 119;
		rotate(idx + 1);
		for (int i = 0; i < 3; i++) {
			G[y][x] >>= 1;
			rotate(idx + 1);
		}
		break;
	case 5:
		G[y][x] = 15;
		rotate(idx + 1);
		break;
	default:
		break;
	}
}


int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			if (G[i][j] == 0) side++;
			else if (G[i][j] >= 1 && G[i][j] <= 5)
				v.push_back({ i,j,G[i][j] });
			else G[i][j] = -1;
		}
	}

	ans = 1e9;
	sz = v.size();

	rotate(0);

	cout << ans;

	return 0;
}