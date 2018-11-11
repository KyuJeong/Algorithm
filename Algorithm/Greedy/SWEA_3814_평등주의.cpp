#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> v;

bool search(int m)
{
	vector <int> vt = v;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (vt[i] - vt[i - 1] > m)
		{
			int tmp = vt[i];
			vt[i] = vt[i - 1] + m;
			cnt += tmp - vt[i];
			if (cnt > k) return false;
		}
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (vt[i] - vt[i + 1] > m)
		{
			int tmp = vt[i];
			vt[i] = vt[i + 1] + m;
			cnt += tmp - vt[i];
			if (cnt > k) return false;
		}
	}
	return true;
}

int f()
{
	int l = 0;
	int r = 1000000000;
	int ans = r;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (search(m))
		{
			ans = min(ans, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> k;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		int ans = f();
		cout << "#" << t << " " << ans << "\n";

		v.clear();
	}

	return 0;
}