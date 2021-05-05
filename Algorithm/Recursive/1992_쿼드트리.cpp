#include <bits/stdc++.h>

using namespace std;

int n;
char G[65][65];

bool chk(string* arr) {
	if (arr[0].size() == 1 && arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3]) return true;
	else return false;
}

string solve(int y, int x, int sz) {
	string ret;
	if (sz == 1) {
		ret = G[y][x];
		return ret;
	}
	string arr[4];
	arr[0] = solve(y, x, sz / 2);
	arr[1] = solve(y, x + sz / 2, sz / 2);
	arr[2] = solve(y + sz / 2, x, sz / 2);
	arr[3] = solve(y + sz / 2, x + sz / 2, sz / 2);
	if (chk(arr)) ret = G[y][x];
	else ret = "(" + arr[0] + arr[1] + arr[2] + arr[3] + ")";

	return ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> G[i];

	cout << solve(0, 0, n);

	return 0;
}