#include <bits/stdc++.h>

using namespace std;

#define MAX 5000001
#define INF 2e9

int t[MAX * 2];
int N, L;

void build() // build the tree
{
	for (int i = N - 1; i > 0; i--)
		t[i] = min(t[2 * i], t[2 * i + 1]);
}

int solve(int l, int r) // sum on interval [l, r)
{
	int _min = INF;
	l--;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			_min = min(_min, t[l++]);
		
		if (r & 1)
			_min = min(_min, t[--r]);
	}

	return _min;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> L;

	for (int i = 1; i <= 2 * N; i++)
		t[i] = INF;

	for (int i = 0; i < N; i++)
	{
		cin >> t[N + i];
	}

	build();

	int a, b;

	for (int i = 1; i <= N; i++)
	{
		a = max(1, i - L + 1);
		b = i;
		cout << solve(a, b) << " ";
	}

	return 0;
}