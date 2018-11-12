#include <bits/stdc++.h>

using namespace std;

int n, c;
vector <int> v;

bool search(int m)
{
	int pre = v[0];
	int cnt = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - pre >= m)
		{
			cnt++;
			pre = v[i];
		}
		if (cnt == c)
			return true;
	}
	return false;
}

int f()
{
	int l = 1;
	int r = 1000000000;
	int ret = 0;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (search(m))
		{
			l = m + 1;
			ret = m;
		}
		else
			r = m - 1;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> c;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int ans = f();
	cout << ans;

	return 0;
}