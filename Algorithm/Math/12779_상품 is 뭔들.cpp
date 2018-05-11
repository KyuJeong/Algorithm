#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b;
ll cnt;

ll GCD(ll x, ll y)
{
	if (x < y)
		swap(x, y);
	while (y > 0)
	{
		ll tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> a >> b;

	ll as = sqrt(a);
	ll bs = sqrt(b);

	ll cnt = bs - as;

	if (cnt == 0)
		cout << "0";
	else
	{
		ll tot = b - a;
		ll gcd = GCD(cnt, tot);
		cout << cnt / gcd << "/" << tot / gcd;
	}

	return 0;
}