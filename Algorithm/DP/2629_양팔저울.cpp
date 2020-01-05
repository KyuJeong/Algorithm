#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[31];
bool d[31][15001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0][a[0]] = true;
	for (int i = 1; i < n; i++) {
		int w = a[i];
		d[i][w] = true;
		for (int j = 0; j <= 15000; j++) {
			if (d[i - 1][j]) {
				d[i][j] = true;
				d[i][j + w] = true;
				if (j - w >= 0) d[i][j - w] = true;
				if (w - j >= 0) d[i][w - j] = true;
			}
		}
	}

	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x > 15000 || !d[n - 1][x]) cout << "N ";
		else cout << "Y ";
	}

	return 0;
}