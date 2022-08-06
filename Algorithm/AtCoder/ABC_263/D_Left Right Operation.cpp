#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 200002

int n;
ll l, r;
ll A[MAX];
ll dp_x[MAX];
ll dp_y[MAX];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = 1; i <= n; i++)
		dp_x[i] = min(dp_x[i - 1] + A[i], l * i);

	for (int i = n; i >= 1; i--)
		dp_y[i] = min(dp_y[i + 1] + A[i], r * (n - i + 1));

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += A[i];

	for (int i = 0; i <= n; i++)
		ans = min(ans, dp_x[i] + dp_y[i + 1]);

	cout << ans;

	return 0;
}