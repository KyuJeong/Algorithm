#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll phi(ll n)
{
	ll ans = n;
	for (ll i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			ans -= ans / i;
		}
	}

	if (n > 1)
		ans -= ans / n;
	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	ll n;

	cin >> n;

	cout << phi(n);

	return 0;
}