#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int n;
vector <pair <int, int>> vt;
vi dp;
int idx[100001];
bool chk[500001];

vi solve() {

	dp.push_back(-1);

	for (int i = 0; i < n; i++) {
		if (dp.back() < vt[i].second) {
			dp.push_back(vt[i].second);
			idx[i] = dp.size() - 1;
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), vt[i].second);
			*it = vt[i].second;
			idx[i] = it - dp.begin();
		}
	}

	vi lis;
	int cnt = dp.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (idx[i] == cnt) {
			lis.push_back(vt[i].second);
			cnt--;
		}
		if (cnt == 0) break;
	}

	for (auto i : lis) {
		chk[i] = true;
	}

	vi ans;
	for (auto i : vt) {
		if (!chk[i.second])
			ans.push_back(i.first);
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vt.push_back({ a,b });
	}

	sort(vt.begin(), vt.end());

	vi ans = solve();
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << "\n";
	}

	return 0;
}