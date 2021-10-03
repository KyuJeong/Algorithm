#include <bits/stdc++.h>

using namespace std;

int n, k;
bool chk[100001];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	if (k == 0) {
		cout << n - k;
		return 0;
	}

	queue <int> q;
	if (n == 0) {
		q.push(0);
		chk[0] = true;
	}
	else {
		while (n <= 100000) {
			if (n == k) {
				cout << 0;
				return 0;
			}
			q.push(n);
			chk[n] = true;

			n *= 2;
		}
	}

	int sec = 1;
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int cur = q.front() - 1;
			while (cur > 0 && cur <= 100000) {
				if (cur == k) {
					cout << sec;
					return 0;
				}
				if (!chk[cur]) {
					q.push(cur);
					chk[cur] = true;
				}
				cur *= 2;
			}

			cur = q.front() + 1;
			while (cur <= 100000) {
				if (cur == k) {
					cout << sec;
					return 0;
				}
				if (!chk[cur]) {
					q.push(cur);
					chk[cur] = true;
				}
				cur *= 2;
			}
			q.pop();
		}
		sec++;
	}

	return 0;
}