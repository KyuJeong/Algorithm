#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 2e9

typedef pair <int, int> pii;

pii t[MAX * 2];
int N, M;

void build() // build the tree
{
	for (int i = N - 1; i > 0; i--)
	{
		t[i].first = min(t[2 * i].first, t[2 * i + 1].first);
		t[i].second = max(t[2 * i].second, t[2 * i + 1].second);
	}
}

pii solve(int l, int r) // sum on interval [l, r)
{
	int _min = INF;
	int _max = -INF;
	l--;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
		{
			_min = min(_min, t[l].first);
			_max = max(_max, t[l++].second);
		}
		if (r & 1)
		{
			_min = min(_min, t[--r].first);
			_max = max(_max, t[r].second);
		}
	}

	return{ _min, _max };
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= 2 * N; i++)
	{
		t[i] = { INF , -INF };
	}

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		t[N + i] = { tmp, tmp };
	}

	build();

	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		
		pii ans = solve(a, b);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}