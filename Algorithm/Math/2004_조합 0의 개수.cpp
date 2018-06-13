#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	ll n, m;

	cin >> n >> m;

	if (n == m || m == 0)
	{
		cout << "0";
		return 0;
	}

	ll up = 0;
	ll sub = 0;
	ll down = 0;

	ll div = 5;

	while (div <= n)
	{
		up += (n / div);
		sub += ((n - m) / div);
		down += (m / div);

		div *= 5;
	}

	int five = up - sub - down;

	div = 2;

	up = 0;
	sub = 0;
	down = 0;

	while (div <= n)
	{
		up += (n / div);
		sub += ((n - m) / div);
		down += (m / div);

		div *= 2;
	}

	int two = up - sub - down;

	cout << min(five, two);

	return 0;
}