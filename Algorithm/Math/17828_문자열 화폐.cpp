#include <bits/stdc++.h>

using namespace std;

int n, x;
char ans[5000001];

int main() {

	cin >> n >> x;

	if (n * 26 < x || n > x) {
		cout << "!";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		ans[i] = 'A';
		x--;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (x >= 25) {
			ans[i] = 'Z';
			x -= 25;
		}
		else {
			ans[i] = 'A' + x;
			break;
		}
	}

	cout << ans;

	return 0;
}