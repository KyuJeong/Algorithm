#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000001

typedef vector <int> vi;

int p[MAX_N], arr[MAX_N];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vi v;
	v.push_back(-2e9);

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[i] = tmp;
		if (v.back() < tmp) {
			v.push_back(tmp);
			p[i] = v.size() - 1;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), tmp);
			p[i] = it - v.begin();
			*it = tmp;
		}
	}

	vi ans;
	int idx = v.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == idx) {
			ans.push_back(arr[i]);
			idx--;
		}
		if (idx == 0) break;
	}
	reverse(ans.begin(), ans.end());

	cout << v.size() - 1 << "\n";
	for (auto i : ans)
		cout << i << " ";

	return 0;
}