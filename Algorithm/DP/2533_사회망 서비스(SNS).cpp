#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001

int n;
vector <int> t[MAXN];
int u, v;
int d[MAXN][2]; // [][0] : 얼리어답터 / [][1] : 얼리어답터x

void solve(int par, int x) {
	d[x][0] = 1;
	for (auto i : t[x]) {
		if (i == par) continue;
		solve(x, i);
		d[x][0] += min(d[i][0], d[i][1]);
	}
	for (auto i : t[x]) {
		if (i == par) continue;
		d[x][1] += d[i][0];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}

	solve(0, 1);
	cout << min(d[1][0], d[1][1]);

	return 0;
}