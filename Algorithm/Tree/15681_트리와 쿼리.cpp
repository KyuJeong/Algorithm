#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector <int> tree[100001];
bool chk[100001];
int sum[100001];

int dfs(int x) {
	chk[x] = true;
	int ret = 1;
	for (auto i : tree[x]) {
		if (!chk[i]) {
			ret += dfs(i);
		}
	}
	return sum[x] = ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(r);
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << sum[x] << "\n";
	}

	return 0;
}