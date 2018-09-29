#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int x, n;

	cin >> x >> n;

	if (n == 1)
	{
		if (x >= 0) cout << "0";
		else cout << "INFINITE";
		return 0;
	}

	if (n & 1)
	{
		cout << "ERROR";
		return 0;
	}
	if (x <= 0)
	{
		cout << "0";
		return 0;
	}
	if (n == 0)
	{
		cout << "INFINITE";
		return 0;
	}

	n >>= 1;
	if (x % n == 0)
		cout << (x / n) - 1;
	else
		cout << x / n;

	return 0;
}