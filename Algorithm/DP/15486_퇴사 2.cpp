#include <bits/stdc++.h>

using namespace std;

#define MAX 1500002

int n;
int d[MAX];
int t[MAX];
int p[MAX];
int _max, ans;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		if (_max < d[i]) _max = d[i];
		if (i + t[i] > n + 1) continue;
		if (d[i + t[i]] < _max + p[i]) d[i + t[i]] = _max + p[i];
		if (ans < d[i + t[i]]) ans = d[i + t[i]];
	}

	cout << ans;

	return 0;
}