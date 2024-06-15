#include <bits/stdc++.h>

using namespace std;

#define MAX 140000

int N, M, K;
int sz;
int t[MAX * 2];

void update(int pos, int val) {
	pos += sz - 1;
	t[pos] = val;
	pos >>= 1;
	while (pos) {
		t[pos] = min(t[pos << 1], t[pos << 1 | 1]);
		pos >>= 1;
	}
}

int query(int l, int r) {
	l += sz - 1;
	r += sz - 1;
	int ret = 1e9;

	while (l <= r) {
		if (l & 1)
			ret = min(ret, t[l++]);
		if (!(r & 1))
			ret = min(ret, t[r--]);
		l >>= 1;
		r >>= 1;
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	sz = 1;
	while (sz < N)
		sz <<= 1;

	for (int i = 0; i < sz * 2; i++)
		t[i] = 1e9;

	for (int i = 0; i < N; i++)
		cin >> t[sz + i];

	for (int i = sz - 1; i > 0; i--)
		t[i] = min(t[i << 1], t[i << 1 | 1]);

	int a, b, c;

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << query(b, c) << "\n";
	}

	return 0;
}