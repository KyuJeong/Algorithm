#include <bits/stdc++.h>

using namespace std;

int n;
int arr[51];
vector <int> v[51];
int ans = 0;

void dfs(int x, int cnt) {
	for (auto i : v[x]) {
		if (i == n) {
			ans = cnt;
		}
		dfs(i, cnt + 1);
	}

	return;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1 + 1; i <= n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}

	dfs(1, 0);
	cout << ans + 1;

	return 0;
}