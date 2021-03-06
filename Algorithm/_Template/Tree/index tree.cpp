#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1100000

int N, M, K;
int sz;
ll t[MAX * 2];

void update(int pos, int val)
{
	pos += sz - 1;
	while (pos)
	{
		t[pos] += val;
		pos >>= 1;
	}
}

ll query(int l, int r)
{
	l += sz - 1;
	r += sz - 1;
	ll ret = 0;

	while (l <= r)
	{
		if (l & 1) // 시작위치가 홀수라면 부모가 아닌 자기자신만 더해줘야함
			ret += t[l++];
		if (!(r & 1)) // 끝위치가 짝수라면 부모가 아닌 자기자신만 더해줘야함
			ret += t[r--];
		l >>= 1; // 부모로 이동
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
	while (sz < N) // 시작위치 지정(2의 제곱수로)
		sz <<= 1;

	for (int i = 0; i < N; i++)
		cin >> t[sz + i];

	for (int i = sz - 1; i > 0; i--)
		t[i] = t[i << 1] + t[i << 1 | 1];

	int a, b, c;

	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll dif = c - t[b + sz - 1];
			update(b, dif);
		}
		else
			cout << query(b, c) << "\n";
	}

	return 0;
}