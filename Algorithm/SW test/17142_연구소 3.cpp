#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

struct Node {
	int y;
	int x;
};

int n, m;
int G[51][51];
int total;
vector <Node> virus;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

int bfs(vector <Node> v) {
	bool visit[51][51] = { false };
	queue <Node> q;

	for (auto i : v) {
		visit[i.y][i.x] = true;
		q.push(i);
	}

	int cnt = 0;
	int sec = 1;
	int sz = q.size();
	while (!q.empty()) {
		for (int i = 0; i < sz; i++) {
			Node cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = cur.y + my[j];
				int nx = cur.x + mx[j];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (G[ny][nx] == 1 || visit[ny][nx]) continue;
				if (G[ny][nx] == 0) cnt++;
				if (cnt == total) return sec;
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
		sec++;
		sz = q.size();
	}
	return INF;
}

int solve() {
	int ret = INF;

	int len = virus.size();
	vector <int> arr;
	for (int i = 0; i < len - m; i++)
		arr.push_back(0);
	for (int i = 0; i < m; i++)
		arr.push_back(1);

	do {
		vector <Node> v;
		for (int i = 0; i < len; i++) {
			if (arr[i] == 1) v.push_back(virus[i]);
		}
		int tmp = bfs(v);
		if (ret > tmp) ret = tmp;

	} while (next_permutation(arr.begin(), arr.end()));

	if (ret == INF) ret = -1;
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
			if (G[i][j] == 0) total++;
			else if (G[i][j] == 2) virus.push_back({ i,j });
		}
	}

	if (total == 0) {
		cout << "0";
		return 0;
	}

	int ans = solve();
	cout << ans;

	return 0;
}