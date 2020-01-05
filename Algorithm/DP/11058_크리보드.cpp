#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[101];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= 6; i++)
		d[i] = i;
	for (int i = 7; i <= n; i++) {
		for (int j = 1; j <= i - 3; j++) {
			ll cnt = i - j - 1;
			d[i] = max(d[i], d[j] * cnt);
		}
	}

	cout << d[n];

	return 0;
}