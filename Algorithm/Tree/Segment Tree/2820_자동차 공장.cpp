#include <bits/stdc++.h>

using namespace std;

#define MAXN 524289

typedef long long ll;

int N, M;
int v, w;
vector <int> G[MAXN];
int cost[MAXN];
bool check[MAXN];
int n;
ll t[MAXN * 4], lazy[MAXN * 4];
int in[MAXN], out[MAXN];
int idx = 1;

void dfs(int x)
{
	t[n + idx - 1] = cost[x];
	in[x] = idx++;
	check[x] = true;
	for (auto i : G[x])
	{
		if (!check[i])
			dfs(i);
	}
	t[n + idx - 1] = cost[x];
	out[x] = idx++;
}

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
	ll cnt = 1;

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

	cin >> N >> M;
	cin >> cost[1];

	n = 1;
	while (n < N * 2)
		n <<= 1;

	for (int i = 2; i <= N; i++)
	{
		cin >> w >> v;
		G[v].push_back(i);
		cost[i] = w;
	}

	dfs(1);

	char q;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> q;
		if (q == 'p')
		{
			cin >> a >> b;
			update(in[a] + 1, out[a] - 1, b);
		}
		else
		{
			cin >> a;
			cout << query(in[a], in[a]) << "\n";
		}
	}

	return 0;
}