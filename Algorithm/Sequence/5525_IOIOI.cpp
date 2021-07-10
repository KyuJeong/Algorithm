#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int ans = 0;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> s;
	s = 'X' + s;

	int cnt = 0;
	bool flag = false;
	for (int i = 1; i <= m; i++) {
		if (!flag && s[i] == 'I') {
			flag = true;
			continue;
		}
		if (flag) {
			if (s[i] == 'O' && s[i - 1] != 'I') {
				cnt = 0;
				flag = false;
			}
			if (s[i] == 'I') {
				if (s[i - 1] == 'I') cnt = 0;
				else {
					flag = true;
					cnt++;
					if (cnt >= n) ans++;
				}
			}

		}
	}

	cout << ans;

	return 0;
}