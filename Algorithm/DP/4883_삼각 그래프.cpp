#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
int G[100001][3];
int d[100001][3];

int f() {

	d[0][0] = G[0][1];
	d[0][1] = G[0][1];
	d[0][2] = G[0][1] + G[0][2];

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][0], d[i - 1][1]) + G[i][0];
		d[i][1] = min({ d[i - 1][0],d[i - 1][1],d[i - 1][2],d[i][0] }) + G[i][1];
		d[i][2] = min({ d[i - 1][1],d[i - 1][2],d[i][1] }) + G[i][2];
	}

	return d[n - 1][1];
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (1) {
		tc++;
		memset(d, 0, sizeof(d));

		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> G[i][j];
			}
		}

		int ans = f();
		cout << tc << ". " << ans << "\n";
	}

	return 0;
}