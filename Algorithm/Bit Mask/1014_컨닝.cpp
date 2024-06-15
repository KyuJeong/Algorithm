#include <bits/stdc++.h>

using namespace std;

struct BIT {
	int val;
	int cnt;
};

int t;
int n, m;
string G[11];
int d[11][1025];
vector <BIT> bit_list;

void make_bit() {
	bit_list.clear();
	int len = pow(2, m);
	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				if (i & (1 << (j + 1))) {
					cnt = -1;
					break;
				}
				else {
					cnt++;
				}
			}
		}
		if (cnt != -1) {
			bit_list.push_back({ i, cnt });
		}
	}
}

bool chk_seat(int y, int val) {
	for (int x = 0; x < m; x++) {
		if (val & (1 << x) && G[y][m - 1 - x] == 'x') {
			return false;
		}
	}
	return true;
}

bool chk_seat2(int cur_val, int pre_val) {
	for (int x = 0; x < m; x++) {
		if (cur_val & (1 << x)) {
			if (x > 0 && pre_val & (1 << (x - 1))) {
				return false;
			}
			if (pre_val & (1 << (x + 1))) {
				return false;
			}
		}
	}
	return true;
}

int solve() {
	memset(d, 0, sizeof(d));
	int ans = 0;
	for (auto i : bit_list) {
		int cnt = 0;
		if (chk_seat(0, i.val)) {
			d[0][i.val] = i.cnt;
			ans = max(ans, d[0][i.val]);
		}

	}
	for (int y = 1; y < n; y++) {
		for (auto cur : bit_list) {
			if (!chk_seat(y, cur.val)) continue;
			for (auto pre : bit_list) {
				if (!chk_seat(y - 1, pre.val)) {
					d[y][cur.val] = max(d[y][cur.val], cur.cnt);
				}
				else if (chk_seat2(cur.val, pre.val)) {
					d[y][cur.val] = max(d[y][cur.val], d[y - 1][pre.val] + cur.cnt);
				}
				ans = max(ans, d[y][cur.val]);
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> G[i];
		make_bit();
		cout << solve() << "\n";
	}

	return 0;
}