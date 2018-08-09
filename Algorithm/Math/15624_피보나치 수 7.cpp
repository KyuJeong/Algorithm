#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll fibonacci(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;

	ll ret;
	if (x & 1)
	{
		ll a = fibonacci(x / 2);
		ll b = fibonacci(x / 2 + 1);
		a = (a * a) % MOD;
		b = (b * b) % MOD;
		ret = (a + b) % MOD;
	}
	else
	{
		ll a = fibonacci(x / 2 - 1);
		ll b = fibonacci(x / 2);
		ret = (2 * a + b) % MOD;
		ret = (ret * b) % MOD;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << fibonacci(n);

	return 0;
}