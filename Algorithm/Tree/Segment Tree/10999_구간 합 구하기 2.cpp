#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1100000

ll t[MAX * 2];
int N, M, K;
int n;

void build() // build the tree
{
	for (int i = n - 1; i > 0; i--)
		t[i] = t[2 * i] + t[2 * i + 1];
}

void modify(int l, int r, int value)
{
	l -= 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			t[l++] += value;
		if (r & 1)
			t[--r] += value;
	}
}

void update(int pos, int val) // set value at position p
{
	pos--; // index 1부터 시작
	for (t[pos += n] = val; pos > 1; pos >>= 1)
		t[pos >> 1] = t[pos] + t[pos ^ 1];
}

ll sum(int l, int r) // sum on interval [l, r)
{
	ll ans = 0;
	l--; // index 1부터 시작
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			ans += t[l++];
		if (r & 1)
			ans += t[--r];
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	n = 1;
	while (n < N)
		n *= 2;
	for (int i = 0; i < N; i++)
		cin >> t[n + i];

	build();

	int a, b, c;

	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << sum(b, c) << "\n";
	}

	return 0;
}