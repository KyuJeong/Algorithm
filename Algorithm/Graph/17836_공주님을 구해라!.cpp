#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

struct Node {
	int y;
	int x;
	int s;
	Node() {}
	Node(int _y, int _x, int _s) : y(_y), x(_x), s(_s) {}
};

int n, m, t;
int G[101][101];
bool visit[101][101];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

int bfs() {
	queue <Node> q;
	q.push({ 0,0,0 });
	visit[0][0] = true;

	int ret = INF;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + my[i];
			int nx = cur.x + mx[i];
			int ns = cur.s + 1;
			if (ns > t) break;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx]) continue;
			visit[ny][nx] = true;
			if (G[ny][nx] == 1) continue;
			if (G[ny][nx] == 2) ret = ns + (n - ny) + (m - nx) - 2;
			if (ny == n - 1 && nx == m - 1) {
				ret = min(ret, ns);
				return ret;
			}
			q.push({ ny,nx,ns });
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> G[i][j];

	int ans = bfs();

	if (ans > t) cout << "Fail";
	else cout << ans;

	return 0;
}