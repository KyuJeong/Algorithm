#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	int cnt = 0;
	while (1) {
		cnt++;
		ll num = cnt;
		ll add = cnt + 1;
		for (int i = 0; i < cnt + 1; i++) {
			num += add;
			add *= 2;
		}
		if (n <= num) {
			cout << cnt;
			break;
		}
	}

	return 0;
}