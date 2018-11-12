#include <bits/stdc++.h>

using namespace std;

int tc;
int n, k;
vector <int> v;
vector <int> w;

bool search(int m)
{
	int idx = 0;
	int len = w[idx];
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= m)
			cnt++;
		else
		{
			cnt = 0;
			continue;
		}
		if (cnt == len)
		{
			cnt = 0;
			if (++idx == w.size()) return true;
			len = w[idx];
		}
	}
	return false;
}

int f()
{
	int l = 1;
	int r = 200000;
	int ans = 200000;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (search(m))
		{
			ans = min(m, ans);
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{
		cin >> n >> k;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		w.resize(k);
		for (int i = 0; i < k; i++)
			cin >> w[i];

		int ans = f();
		cout << "#" << test << " " << ans << "\n";

		v.clear();
		w.clear();
	}

	return 0;
}