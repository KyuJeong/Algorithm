#include <bits/stdc++.h>

using namespace std;

int n;
int G[129][129];
int cnt[2];

bool chk(int arr[]) {
	if (arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3]) return true;
	else return false;
}

int solve(int y, int x, int sz) {
	if (sz == 0) return 0;
	if (sz == 1) return G[y][x];

	int num[4];
	num[0] = solve(y, x, sz / 2);
	num[1] = solve(y, x + sz / 2, sz / 2);
	num[2] = solve(y + sz / 2, x, sz / 2);
	num[3] = solve(y + sz / 2, x + sz / 2, sz / 2);

	if (chk(num) && num[0] != -1) return num[0];
	else {
		for (int i = 0; i < 4; i++) cnt[num[i]]++;
		return -1;
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> G[i][j];

	solve(0, 0, n);

	cout << cnt[0] << "\n";
	cout << cnt[1];

	return 0;
}