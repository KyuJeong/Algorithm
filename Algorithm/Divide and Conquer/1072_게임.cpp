#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	double x, y;
	while (cin >> x >> y)
	{
		int z = (y * 100) / x;
		if (z >= 99)
		{
			cout << "-1\n";
			continue;
		}

		int l = 0;
		int r = 2000000000;
		int m;
		while (l <= r)
		{
			m = (l + r) / 2;
			int t = ((y + m) * 100) / (x + m);
			if (t > z)
				r = m - 1;
			else
				l = m + 1;
		}

		cout << l << "\n";
	}
	return 0;
}