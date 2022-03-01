#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll A[5001];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	sort(A, A + n);

	ll _min = 3e9;
	ll ans[3];
	for (int i = 2; i < n; i++) {
		int l = 0;
		int r = i - 1;
		while (l < r) {
			ll sum = A[l] + A[r] + A[i];
			if (abs(sum) < _min) {
				_min = abs(sum);
				ans[0] = A[l];
				ans[1] = A[r];
				ans[2] = A[i];
			}
			if (sum < 0) l++;
			else if (sum == 0) {
				cout << ans[0] << " " << ans[1] << " " << ans[2];
				return 0;
			}
			else r--;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];

	return 0;
}