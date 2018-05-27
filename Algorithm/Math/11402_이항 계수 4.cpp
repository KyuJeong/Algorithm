#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, R, P;
stack <ll> a;
stack <ll> b;
ll DP[2001][2001];

// 필요한 수 : k

ll Lucas(ll x, ll y)
{
	ll &ret = DP[x][y];
	if (ret != -1)
		return ret;

	if (y == 0 || y == x)
		return 1;

	if (y > x)
		return 0;

	return ret = (Lucas(x - 1, y - 1) + Lucas(x - 1, y)) % P;
}

void GetDigit()
{
	ll m = N;
	ll n = R;

	while (m > 0)
	{
		a.push(m % P);
		b.push(n % P);
		m /= P;
		n /= P;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> R >> P;

	memset(DP, -1, sizeof(DP));
	
	GetDigit();

	ll ans = 1;

	while (!a.empty())
	{
		ll m = a.top();
		a.pop();

		ll n = b.top();
		b.pop();

		ans = (ans * Lucas(m, n)) % P;
	}
	
	cout << ans;

	return 0;
}