#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int s;
	int e;
	int len;
};

int n, d;
Edge edge[10001];
int dp[10001];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> edge[i].s >> edge[i].e >> edge[i].len;
	}

	sort(edge, edge + n, [](const Edge &e1, const Edge &e2) {
		return e1.e < e2.e;
	});

	int _min = 0;
	for (int i = 1; i <= d; i++) {
		dp[i] = ++_min;
		for (int j = 0; j < n; j++) {
			if (edge[j].e == i) {
				int new_len = dp[edge[j].s] + edge[j].len;
				if (dp[i] > new_len) {
					dp[i] = new_len;
					_min = new_len;
				}
			}
		}
	}

	cout << dp[d];

	return 0;
}