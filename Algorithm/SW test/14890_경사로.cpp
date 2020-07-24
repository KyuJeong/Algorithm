#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans;
int G[202][101];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> G[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i + n][j] = G[j][i];

	for (int i = 0; i < n * 2; i++) {
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++) {
			if (G[i][j] == G[i][j + 1]) cnt++;
			else if (G[i][j] == G[i][j + 1] - 1 && cnt >= k) cnt = 1;
			else if (G[i][j] == G[i][j + 1] + 1 && cnt >= 0) cnt = 1 - k;
			else break;
		}
		if (j == n - 1 && cnt >= 0) ans++;
	}

	cout << ans;

	return 0;
}