#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll arr[100001];
ll s, f;
ll sum[100001];
ll maxx;
ll ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cin >> s >> f;

	ll dif = f - s;

	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}

	maxx = sum[dif];
	ans = dif + s - 1;

	for (int i = 1; i <= n; i++)
	{
		ll tmp = sum[i + dif] - sum[i];
		if (maxx == tmp)
		{
			if (s - i > 0)
				ans = min(ans, s - i);
		}
		
		else if (maxx < tmp)
		{
			ans = i + dif + s - 1;
			maxx = tmp;
		}
	}

	cout << ans;

	return 0;
}