#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
vector <pii> v;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ s,1 });
		v.push_back({ e,0 });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	int ans = 0;
	for (auto i : v) {
		if (i.second == 1) {
			cnt++;
			ans = max(ans, cnt);
		}
		else {
			cnt--;
		}
	}

	cout << ans;

	return 0;
}