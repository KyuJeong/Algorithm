#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef long long ll;

int n;
ll dp[11][11][11][11][11][6][6];

ll f(int p[], int fst, int snd, int rem)
{
	ll &ret = dp[p[1]][p[2]][p[3]][p[4]][p[5]][fst][snd];
	if (ret != -1) return ret;
	if (rem == 0) return 1;

	ll cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] > 0 && fst != i && snd != i)
		{
			p[i]--;
			cnt += f(p, snd, i, rem - 1);
			p[i]++;
		}
	}
	return ret = cnt;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	int cnt = 0;

	int biz[6] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> biz[i];
		cnt += biz[i];
	}

	ll ans = f(biz, 0, 0, cnt);

	cout << ans;

	return 0;
}