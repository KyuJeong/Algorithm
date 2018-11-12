#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> v;

int f()
{
	int l = 0;
	int r = m;
	int ret = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int ans = 0;
		for (auto i : v)
		{
			if (i < mid) ans += i;
			else ans += mid;
		}
		if (ans == m)
			return mid;
		else if (ans < m)
		{
			l = mid + 1;
			ret = max(ret, mid);
		}
		else
			r = mid - 1;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin >> m;

	int ans = f();
	int _max = 0;
	for (auto i : v)
		if (_max < i) _max = i;

	if (ans > _max) ans = _max;
	cout << ans;

	return 0;
}