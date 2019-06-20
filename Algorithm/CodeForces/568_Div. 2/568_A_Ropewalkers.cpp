#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[3];
ll b;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a[0] >> a[1] >> a[2] >> b;

	sort(a, a + 3);

	ll ans = 0;
	ans += max(b - abs(a[1] - a[0]), (ll)0);
	ans += max(b - abs(a[2] - a[1]), (ll)0);


	cout << ans;
	return 0;
}