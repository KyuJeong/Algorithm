#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1000001

ll t[MAX * 2];
int N, M, K;

void build() // build the tree
{
	for (int i = N - 1; i > 0; i--)
		t[i] = t[2 * i] + t[2 * i + 1];
}

void update(int pos, int val) // set value at position p
{
	pos--; // index 1부터 시작
	for (t[pos += N] = val; pos > 1; pos >>= 1)
		t[pos >> 1] = t[pos] + t[pos ^ 1];
}

ll sum(int l, int r) // sum on interval [l, r)
{
	ll ans = 0;
	l--; // index 1부터 시작
	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
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
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> t[N + i];
	
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