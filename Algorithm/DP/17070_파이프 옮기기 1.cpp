#include <bits/stdc++.h>

using namespace std;

int n;
int G[17][17];
int d[17][17][3];

void solve() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (G[i][j] == 1) continue;
			d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][2];
			d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];
			if (G[i - 1][j] == 1 || G[i][j - 1] == 1) continue;
			d[i][j][2] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
		}
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> G[i][j];
		}
	}

	d[0][1][0] = 1;

	for (int i = 2; i < n - 1; i++) {
		if (G[0][i] == 1) break;
		d[0][i][0] = d[0][i - 1][0];
	}

	solve();
	int ans = d[n - 1][n - 1][0] + d[n - 1][n - 1][1] + d[n - 1][n - 1][2];
	cout << ans;

	return 0;
}