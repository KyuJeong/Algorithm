#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

struct Rail
{
	ll a, b;
	Rail() {}
	Rail(ll _a, ll _b) : a(_a), b(_b) {}
};

bool operator < (const Rail &r1, const Rail &r2)
{
	return r1.a * r2.b + r1.b > r2.a * r1.b + r2.b;
}

int tc;

int main()
{
	scanf("%d", &tc);

	for (int test = 1; test <= tc; test++)
	{
		int n;
		scanf("%d", &n);
		vector <Rail> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].a >> v[i].b;

		sort(v.begin(), v.end());
		ll ans = 1;
		for (auto i : v)
			ans = (ans * i.a + i.b) % MOD;

		printf("#%d %d\n", test, ans);
	}

	return 0;
}