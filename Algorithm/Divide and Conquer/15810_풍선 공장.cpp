#include <bits/stdc++.h>

using namespace std;

#define MAX 1e12
typedef long long ll;

int N, M;
int a[1000001];
ll r, l;
ll ans;

void Solve()
{
	while (l <= r)
	{
		ll m = (r + l) / 2;

		ll cnt = 0;

		for (int i = 0; i < N; i++)
		{
			cnt += m / a[i];
			if (cnt >= M)
				break;
		}
		if (cnt >= M)
		{
			r = m - 1;
			ans = m;
		}
		else
			l = m + 1;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	l = 1; r = MAX;

	Solve();

	cout << ans;

	return 0;
}