#include <bits/stdc++.h>

using namespace std;

#define MAX 1100000

typedef long long ll;
ll t[MAX * 2];
int n, m, k;
int sz = 1;

void update(int pos, ll val)
{
	pos += sz - 1;
	val -= t[pos];
	while (pos)
	{
		t[pos] += val;
		pos >>= 1;
	}
}

ll query(int l, int r)
{
	l += sz - 1;
	r += sz - 1;
	ll ret = 0;
	while (l <= r)
	{
		if (l & 1)
			ret += t[l++];
		if (!(r & 1))
			ret += t[r--];
		l >>= 1;
		r >>= 1;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	while (sz < n)
		sz <<= 1;

	for (int i = 0; i < n; i++)
		cin >> t[i + sz];

	for (int i = sz - 1; i > 0; i--)
		t[i] = t[i << 1] + t[i << 1 | 1];

	ll a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << query(b, c) << "\n";
	}

	return 0;
}