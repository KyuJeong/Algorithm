#include <bits/stdc++.h>

using namespace std;

int n, m;
int G[101];
int d[101];

void bfs() {
	queue <int> q;
	q.push(1);
	d[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nxt = cur + i;
			if (G[nxt] != 0) nxt = G[nxt];
			if (nxt > 100) break;
			if (d[nxt] < 0) {
				q.push(nxt);
				d[nxt] = d[cur] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n + m; i++) {
		int u, v;
		cin >> u >> v;
		G[u] = v;
	}

	bfs();
	cout << d[100];

	return 0;
}
