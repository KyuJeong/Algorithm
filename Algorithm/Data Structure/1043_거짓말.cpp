#include <bits/stdc++.h>

using namespace std;

#define SIZE 51

int n, m, s;
vector <int> know;
int parent[SIZE];
vector <int> party[SIZE];

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	parent[u] = v;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> s;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < s; i++) {
		int p;
		cin >> p;
		know.push_back(p);
	}

	for (int i = 0; i < m; i++) {
		int l;
		cin >> l;
		for (int j = 0; j < l; j++) {
			int p;
			cin >> p;
			party[i].push_back(p);
		}
		for (int j = 1; j < party[i].size(); j++) {
			merge(party[i][0], party[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		bool chk = false;
		for (auto j : party[i]) {
			for (auto k : know) {
				if (find(j) == find(k)) {
					chk = true;
					break;
				}
			}
			if (chk) break;
		}
		if (!chk) cnt++;
	}

	cout << cnt;

	return 0;
}