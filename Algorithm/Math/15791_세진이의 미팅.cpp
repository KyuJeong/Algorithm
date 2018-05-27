#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll Pow(ll num, ll exp)
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

	int N, M;

	cin >> N >> M;

	if (N - M < M)
		M = N - M;

	ll up = 1;
	ll down = 1;

	for (int i = 0; i < M; i++)
	{
		up = (up * (N - i)) % MOD;
		down = (down * (i + 1)) % MOD;
	}

	ll ans = (up * Pow(down, MOD - 2)) % MOD;

	cout << ans;

	return 0;
}