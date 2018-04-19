#include <iostream>

using namespace std;

#define MOD 1000000007LL

typedef long long ll;

int N, K;

ll Pow(ll num, ll exp)
{
	ll ret = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			ret = ret * num;
			ret %= MOD;
		}

		num = num * num;
		num %= MOD;
		exp /= 2;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	if ((N - K) < K)
		K = N - K;

	ll up = 1;
	ll down = 1;

	for (int i = 0; i < K; i++)
	{
		up = (up * (N - i)) % MOD;
		down = (down * (i + 1)) % MOD;
	}

	ll ans = (up * Pow(down, MOD - 2)) % MOD;

	cout << ans;

	return 0;
}