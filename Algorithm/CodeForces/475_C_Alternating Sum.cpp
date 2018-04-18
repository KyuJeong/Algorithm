#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MOD 1000000009;

typedef long long ll;
typedef long double ld;

ld n, a, b, k;
string s;
ll ans;

ll Calc(ll num, ll exp)
{
	ll ret = 1;
	while (exp != 0)
	{
		if (exp & 1 != 0)
			ret = (ret * num) % MOD;
		num = (num * num) % MOD;
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

		ans += cur;
		ans %= MOD;
	}

	ll cnt = (n + 1) / k;

	ll bn = Calc(b, cnt);
	ll an = Calc(a, cnt);
	
	ll tmp1 = (ans * bn) % MOD;
	ll tmp2 = (ans * an) % MOD;

	ll tmp3 = (tmp1 / tmp2) % MOD;
	ll tmp4 = -ans;
	ll bj = (tmp3 + tmp4);
	bj %= MOD;

	if (bj < 0)
		bj += MOD;

	ll bm = 


	cout << ans;

	return 0;
}