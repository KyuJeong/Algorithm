#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n, m;
vector <pii> v;
int d[10001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].second;

	for (int i = 0; i < n; i++)
		cin >> v[i].first;

	sort(v.begin(), v.end(), [](pii& x, pii& y) {
		if (x.first == y.first) return x.second > y.second;
		return x.first < y.first;
	});

	for (int i = 0; i < n; i++) {
		for (int j = 10000; j >= v[i].first; j--) {
			d[j] = max(d[j], d[j - v[i].first] + v[i].second);
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (d[i] >= m) {
			cout << i;
			break;
		}
	}

	return 0;
}