#include <bits/stdc++.h>

using namespace std;

int cur;
int pre, _max, cnt;
string ans;

int main() {

	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cur;

		if (cur > pre && cur < _max) {
			cout << "NO";
			return 0;
		}
		for (int i = 0; i < cur - _max; i++)
			ans += "+";
		ans += "-";
		pre = cur;
		_max = max(_max, pre);
		cnt++;
	}

	for (auto i : ans)
		cout << i << "\n";

	return 0;
}