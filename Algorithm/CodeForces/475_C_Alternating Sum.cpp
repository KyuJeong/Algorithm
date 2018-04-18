#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MOD 1000000009

typedef long long ll;
typedef long double ld;

ld n, a, b, k;
string s;
ll T;

ll Calc(ll num, ll exp)
{
	ll ret = 1;
	while (exp != 0)
	{
		if (exp & 1 != 0)
		{
			ret = ret * num;
			if (ret >= MOD)
				ret %= MOD;
		}
		num = num * num;
		if (num >= MOD)
			num %= MOD;
		exp >>= 1;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> a >> b >> k;
	cin >> s;

	for (int i = 0; i < k; i++)
	{
		ll l = Calc(a, n - i);
		ll r = Calc(b, i);

		ll cur = l * r;

		if (s[i] == '-')
			cur = -cur;

		cur %= MOD;
		if (cur < 0)
			cur += MOD;

		T += cur;
		T %= MOD;
	}

	ll Q = (n + 1) / k;

	if (Q == 1)
	{
		cout << T;
		return 0;
	}

	ll bn = Calc(b, k);
	ll an = Calc(a, k);
	
	ll r = (bn * Calc(an, MOD - 2LL)) % MOD;

	ll up = Calc(r, Q);
	up--;

	ll down = r - 1;
	if (down == 0)
	{
		ll ans = (T * Q) % MOD;
		cout << ans;
		return 0;
	}
	ll mul = (up * Calc(down, MOD - 2LL)) % MOD;

	ll ans = (T * mul) % MOD;

	cout << ans;

	return 0;
}