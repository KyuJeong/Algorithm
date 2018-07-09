#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1100000

int N, M, K;
int n;
ll t[MAX * 2], lazy[MAX * 2];

void update(int l, int r, ll val)
{
	l += n - 1;
	r += n - 1;
	int cnt = 1;
	while (l <= r)
	{
		if (l & 1)
		{
			lazy[l] += val;
			int k = l >> 1;
			while (k)
			{
				t[k] += val * cnt;
				k >>= 1;
			}
			l++;
		}
		if (!(r & 1))
		{
			lazy[r] += val;
			int k = r >> 1;
			while (k)
			{
				t[k] += val * cnt;
				k >>= 1;
			}
			r--;
		}
		cnt <<= 1;
		l >>= 1;
		r >>= 1;
	}
}

ll query(int l, int r)
{
	l += n - 1;
	r += n - 1;
	ll ret = 0;
	int cnt = 1;

	while (l <= r)
	{
		if (l & 1)
		{
			ret += t[l];
			int k = l;
			while (k)
			{
				ret += lazy[k] * cnt;
				k >>= 1;
			}
			l++;
		}
		if (!(r & 1))
		{
			ret += t[r];
			int k = r;
			while (k)
			{
				ret += lazy[k] * cnt;
				k >>= 1;
			}
			r--;
		}
		cnt <<= 1;
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
	n = 1;
	while (n < N)
		n <<= 1;

	for (int i = 0; i < N; i++)
		cin >> t[n + i];

	for (int i = n - 1; i > 0; i--)
		t[i] = t[i << 1] + t[i << 1 | 1];

	int a, b, c, d;

	for (int i = 0; i < M + K; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			update(b, c, d);
		}
		else
		{
			cin >> b >> c;
			cout << query(b, c) << "\n";
		}
	}

	return 0;
}