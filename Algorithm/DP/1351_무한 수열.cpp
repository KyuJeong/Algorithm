#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, p, q;

map <ll, ll> m;

ll f(ll x)
{
	auto it = m.find(x);
	ll ret = 0;
	if (it != m.end())
		return m[x];
	ret = f(x / p) + f(x / q);
	m[x] = ret;
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> p >> q;
	if (n == 0)
	{
		cout << "1";
		return 0;
	}

	m.insert({ 0,1 });

	ll ans = f(n / p) + f(n / q);
	cout << ans;

	return 0;
}