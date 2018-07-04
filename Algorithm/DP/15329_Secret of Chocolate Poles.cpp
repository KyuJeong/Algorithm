#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int l, k;
ll DP[101];

ll solve(ll cnt)
{
	if (cnt < 0)
		return 0;
	ll &ret = DP[cnt];

	if (ret != -1)
		return ret;

	ret = solve(cnt - 2) + solve(cnt - k - 1);

	if (ret < 0)
		return ret = 0;

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> l >> k;

	memset(DP, -1, sizeof(DP));

	DP[1] = 1;

	if (k % 2 == 0)
		DP[k] = 1;
	else
		DP[k] = 2;

	solve(l);
	solve(l - 1);

	ll ans = 0;
	for (int i = 1; i <= l; i++)
	{
		if (DP[i] != -1)
			ans += DP[i];
	}

	cout << ans;

	return 0;
}