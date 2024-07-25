#include <bits/stdc++.h>

using namespace std;

int n, q;
int G[66][66];
int T[66][66];
bool chk[66][66];
int ans_sum;
int cur_cnt;

void rotate(int y, int x, int sz) {
	int k = sz - 1;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			T[y + j][x + k - i] = G[y + i][x + j];
		}
	}
}
void reduce_ice() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (T[i][j] == 0) G[i][j] = 0;
			else if (T[i][j + 1] != 0 && T[i][j - 1] != 0 && T[i + 1][j] != 0)	G[i][j] = T[i][j];
			else if (T[i][j + 1] != 0 && T[i][j - 1] != 0 && T[i - 1][j] != 0)	G[i][j] = T[i][j];
			else if (T[i - 1][j] != 0 && T[i][j - 1] != 0 && T[i + 1][j] != 0)	G[i][j] = T[i][j];
			else if (T[i - 1][j] != 0 && T[i][j + 1] != 0 && T[i + 1][j] != 0)	G[i][j] = T[i][j];
			else G[i][j] = T[i][j] - 1;
		}
	}
}

void f(int sz) {
	if (sz > 1) {
		for (int i = 1; i <= n; i += sz) {
			for (int j = 1; j <= n; j += sz) {
				rotate(i, j, sz);
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				T[i][j] = G[i][j];
			}
		}
	}
	reduce_ice();
}

void dfs(int y, int x)
{
	ans_sum += G[y][x];
	cur_cnt++;
	chk[y][x] = true;

	if (!chk[y][x + 1] && G[y][x + 1] != 0) dfs(y, x + 1);
	if (!chk[y][x - 1] && G[y][x - 1] != 0) dfs(y, x - 1);
	if (!chk[y + 1][x] && G[y + 1][x] != 0) dfs(y + 1, x);
	if (!chk[y - 1][x] && G[y - 1][x] != 0) dfs(y - 1, x);
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> q;

	n = 1 << n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> G[i][j];

	int l;
	for (int i = 0; i < q; i++) {
		cin >> l;
		f(1 << l);
	}

	int ans_cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chk[i][j] == 0 && G[i][j] > 0) {
				cur_cnt = 0;
				dfs(i, j);
				ans_cnt = max(ans_cnt, cur_cnt);
			}
		}
	}

	cout << ans_sum << "\n";
	cout << ans_cnt << "\n";

	return 0;
}