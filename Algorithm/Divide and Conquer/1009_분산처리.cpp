#include <iostream>

using namespace std;

typedef long long ll;

int T;

ll Solve(int a, int b) {
	ll ret;

	if (b == 1)
		return a % 10;

	if (b % 2 == 0) {
		ll tmp = Solve(a, b / 2);
		ret = (tmp * tmp) % 10;
	}
	else {
		ll tmp = Solve(a, (b - 1) / 2);
		ret = (tmp * tmp * a) % 10;
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;

		ll ans = Solve(a, b);

		if (ans == 0)
			cout << 10 << "\n";
		else
			cout << ans << "\n";
	}

	return 0;
}