#include <iostream>

using namespace std;

#define MOD 1000000007LL
#define MAX 4000000

typedef long long ll;

int N, K;
ll fac[MAX + 1]; // N!
ll inv[MAX + 1]; // N!ÀÇ inverse

ll Pow (ll num, ll exp)
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

	if (N == K || K == 0)
	{
		cout << "1";
		return 0;
	}

	fac[1] = 1;
	for (int i = 2; i <= N; i++)
		fac[i] = (fac[i - 1] * i) % MOD;

	inv[N] = Pow(fac[N], MOD - 2);

	for (int i = N - 1; i >= 1; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;

	ll ans = (fac[N] * inv[K]) % MOD;
	ans = (ans * inv[N - K]) % MOD;

	cout << ans;

	return 0;
}