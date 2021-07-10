#include <bits/stdc++.h>

using namespace std;

int tc, n;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tc;

	while (tc--) {
		cin >> n;
		string s, t;
		map <string, int> mm;

		for (int i = 0; i < n; i++) {
			cin >> s >> t;
			mm[t]++;
		}

		int ans = 1;
		for (auto it : mm) {
			ans *= (it.second + 1);
		}
		cout << ans - 1 << "\n";
	}

	return 0;
}