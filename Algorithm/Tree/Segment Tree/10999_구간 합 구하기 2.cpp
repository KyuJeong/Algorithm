#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1100000

int n;
int height;
ll t[MAX * 2], lazy[MAX * 2];
int N, M, K;

void calc(int p, int leaf)
{
	if (lazy[p] == 0)
		t[p] = t[p << 1] + t[p << 1 | 1];
	else
		t[p] = t[p << 1] + t[p << 1 | 1] + lazy[p] * leaf;
}

void apply(int p, ll value, int leaf)
{
	t[p] += value * leaf;
	if (p < n)
		lazy[p] += value;
}

void push(int l, int r)
{
	int h = height, leaf = 1 << (h - 1);

	for (l += n, r += n - 1; h > 0; --h, leaf >>= 1)
	{
		for (int i = l >> h; i <= r >> h; ++i)
		{
			if (lazy[i] != 0)
			{
				apply(i << 1, lazy[i], leaf);
				apply(i << 1 | 1, lazy[i], leaf);
				lazy[i] = 0;
			}
		}
	}
}

void build(int l, int r) 
{
	int leaf = 2;
	for (l += n, r += n - 1; l > 1; leaf <<= 1)
	{
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i) 
			calc(i, leaf);
	}
}

void update(int l, int r, int value) 
{
	if (value == 0) return;
	push(l, l + 1);
	push(r - 1, r);
	int l0 = l, r0 = r, leaf = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, leaf <<= 1)
	{
		if (l & 1) apply(l++, value, leaf);
		if (r & 1) apply(--r, value, leaf);
	}
	build(l0, l0 + 1);
	build(r0 - 1, r0);
}

ll query(int l, int r)
{
	push(l, l + 1);
	push(r - 1, r);
	ll res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += t[l++];
		if (r & 1)
			res += t[--r];
	}
	return res;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	n = 1;
	while (n < N)
		n *= 2;

	height = floor(log2(n));

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
			update(b - 1, c, d);
		}
		else
		{
			cin >> b >> c;
			cout << query(b - 1, c) << "\n";
		}
	}

	return 0;
}