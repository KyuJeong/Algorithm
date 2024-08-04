#include <bits/stdc++.h>

using namespace std;

int n;
int sour[11];
int bitter[11];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sour[i] >> bitter[i];
	}

	int num = 1 << n;

	int ans = 1e9;
	for (int i = 1; i < num; i++) {
		int s = 1;
		int b = 0;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				s *= sour[j];
				b += bitter[j];
			}
		}
		ans = min(ans, abs(s - b));
	}

	cout << ans;
	return 0;
}