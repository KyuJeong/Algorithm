#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fac[11];
ll d[11][101][101][101];

ll solve(int level, int r, int g, int b)
{
	if (level == 1)
		return min(r, 1) + min(g, 1) + min(b, 1);

	if (d[level][r][g][b]) return d[level][r][g][b];

	ll ret = 0;
	if (level % 3 == 0)
	{
		int cmp = level / 3;
		ll tmp = fac[level] / (fac[cmp] * fac[cmp] * fac[cmp]);
		if (r >= cmp && g >= cmp && b >= cmp)
			ret += tmp * solve(level - 1, r - cmp, g - cmp, b - cmp);
	}

	if (level % 2 == 0)
	{
		int cmp = level / 2;
		ll tmp = fac[level] / (fac[cmp] * fac[cmp]);

		if (r >= cmp && g >= cmp)
			ret += tmp * solve(level - 1, r - cmp, g - cmp, b);

		if (g >= cmp && b >= cmp)
			ret += tmp * solve(level - 1, r, g - cmp, b - cmp);

		if (r >= cmp && b >= cmp)
			ret += tmp * solve(level - 1, r - cmp, g, b - cmp);
	}

	if (r >= level)
		ret += solve(level - 1, r - level, g, b);
	if (g >= level)
		ret += solve(level - 1, r, g - level, b);
	if (b >= level)
		ret += solve(level - 1, r, g, b - level);

	d[level][r][g][b] = ret;
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, r, g, b;
	cin >> n >> r >> g >> b;

	fac[1] = 1;
	for (int i = 2; i <= n; i++)
		fac[i] = fac[i - 1] * i;

	ll ans = solve(n, r, g, b);
	cout << ans;

	return 0;
}