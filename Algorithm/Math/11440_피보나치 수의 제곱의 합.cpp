#include <iostream>
#include <map>

using namespace std;

#define MOD 1000000007LL

typedef long long ll;

ll n;
map <ll, ll> m;

ll Fibonacci(ll x)
{
	if (x == 0 || x == 1)
		return x;

	if (m.count(x) > 0)
		return m[x];

	ll ret;

	if (x % 2 == 1)
	{
		ll a = Fibonacci((x / 2) + 1);
		ll b = Fibonacci(x / 2);
		m[x] = a*a + b*b;
		m[x] %= MOD;
		return m[x];
	}
	else
	{
		ll a = Fibonacci((x / 2) - 1);
		ll b = Fibonacci(x / 2);
		m[x] = (2 * a + b) * b;
		m[x] %= MOD;
		return m[x];
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	ll ans = Fibonacci(n) * Fibonacci(n + 1);
	ans %= MOD;

	cout << ans;

	return 0;
}