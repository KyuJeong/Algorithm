#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <ll> vll;
typedef pair <int, int> pii;

ll n, m, k;
vll v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	ll ans = 0;
	
	for (int srt = 1; srt <= m; srt++)
	{
		int cnt = m;
		ll sum = 0;
		ll pre = 0;
		for (int i = srt; i <= n; i++)
		{
			cnt++;
			sum += v[i];
			if (cnt > m)
			{
				cnt = 1;
				sum -= k;
			}
			else if (cnt < m)
			{
				int num = 0;
				ll tmp = 0;
				for (int j = pre; j >= 1; j--)
				{
					tmp += v[j];
					ans = max(ans, sum + tmp);
					num++;
					if (num + cnt >= m) break;
				}
			}
			if (sum < 0)
			{
				sum = 0;
				cnt = m;
				pre = i;
			}
			ans = max(ans, sum);
		}
		if (cnt < m)
		{
			int num = 0;
			ll tmp = 0;
			for (int j = pre; j >= 1; j--)
			{
				tmp += v[j];
				ans = max(ans, sum + tmp);
				num++;
				if (num + cnt >= m) break;
			}
		}
	}

	cout << ans;

	return 0;
}