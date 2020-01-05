#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> ord;
int ans;

void solve(int a, int b, int cnt, int move) {
	if (cnt == m) {
		ans = min(ans, move);
		return;
	}

	int nxt = ord[cnt];
	if (a > b) swap(a, b);
	if (nxt <= a) solve(nxt, b, cnt + 1, move + abs(a - nxt));
	else if (nxt >= b) solve(a, nxt, cnt + 1, move + abs(b - nxt));
	else {
		solve(ord[cnt], b, cnt + 1, move + abs(a - nxt));
		solve(a, ord[cnt], cnt + 1, move + abs(b - nxt));
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> n >> a >> b >> m;
	ord.resize(m);
	for (int i = 0; i < m; i++)
		cin >> ord[i];

	ans = 987654321;

	solve(a, b, 0, 0);

	cout << ans;

	return 0;
}