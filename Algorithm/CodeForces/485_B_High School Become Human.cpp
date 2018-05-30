#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	ll x, y;

	cin >> x >> y;

	if (x == y)
	{
		cout << "=";
		return 0;
	}

	if (x == 1)
	{
		cout << "<";
		return 0;
	}

	if (y == 1)
	{
		cout << ">";
		return 0;
	}

	if (x == 2 && y == 3)
	{
		cout << "<";
		return 0;
	}

	if (x == 3 && y == 2)
	{
		cout << ">";
		return 0;
	}

	if (x == 4 && y == 2 || x == 2 && y == 4)
	{
		cout << "=";
		return 0;
	}

	if (x > y)
	{
		cout << "<";
		return 0;
	}

	if (x < y)
	{
		cout << ">";
		return 0;
	}

	return 0;
}