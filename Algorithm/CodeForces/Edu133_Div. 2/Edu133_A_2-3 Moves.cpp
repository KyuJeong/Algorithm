#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 1) cout << "2";
		else if (n % 3 == 0) {
			cout << n / 3;
		}
		else if (n % 3 == 1) {
			cout << (n / 3) + 1;
		}
		else cout << (n / 3) + 1;
		cout << "\n";
	}

	return 0;
}