#include <bits/stdc++.h>

using namespace std;

#define MAXN 131073

int N, M;
int n;
int t[MAXN * 4], lazy[MAXN * 4];
int in[MAXN], out[MAXN];
bool visit[MAXN];
vector <int> G[MAXN];
int idx = 1;

void dfs(int x)
{
	t[n + idx - 1] = 0;
	in[x] = idx++;
	visit[x] = true;

	for (auto i : G[x])
	{
		if (visit[i])
			continue;
		dfs(i);
	}
	t[n + idx - 1] = 0;
	out[x] = idx++;
}

void update(int l, int r, int val)
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

int query(int l, int r)
{
	l += n - 1;
	r += n - 1;
	int ret = 0;
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

	cin >> N >> M;

	n = 1;
	while (n < N * 2)
		n <<= 1;

	int u;
	cin >> u;
	for (int i = 2; i <= N; i++)
	{
		cin >> u;
		G[u].push_back(i);
	}

	dfs(1);

	int q, a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> a >> b;
			update(in[a], out[a], b);
		}
		else
		{
			cin >> a;
			cout << query(in[a], in[a]) << "\n";
		}
	}

	return 0;
}