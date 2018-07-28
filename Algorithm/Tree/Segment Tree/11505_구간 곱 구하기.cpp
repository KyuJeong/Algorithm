#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1100000
#define MOD 1000000007

int N, M, K;
int sz;
ll t[MAX * 2];

void update(int pos, int val)
{
	pos += sz - 1;
	t[pos] = val;
	while (pos)
	{
		pos >>= 1;
		t[pos] = (t[pos << 1] * t[pos << 1 | 1]) % MOD;
	}
}

ll query(int l, int r)
{
	l += sz - 1;
	r += sz - 1;
	ll ret = 1;

	while (l <= r)
	{
		if (l & 1)
			ret = (ret * t[l++]) % MOD;
		if (!(r & 1))
			ret = (ret * t[r--]) % MOD;
		l >>= 1;
		r >>= 1;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	sz = 1;
	while (sz < N)
		sz <<= 1;

	for (int i = 0; i < MAX; i++)
		t[i] = 1;

	for (int i = 0; i < N; i++)
		cin >> t[sz + i];

	for (int i = sz - 1; i > 0; i--)
		t[i] = (t[i << 1] * t[i << 1 | 1]) % MOD;

	int a, b, c;

	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << query(b, c) << "\n";
	}

	return 0;
}