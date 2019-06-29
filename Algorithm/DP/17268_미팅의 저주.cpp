#include <bits/stdc++.h>

using namespace std;

#define MOD 987654321LL

typedef long long ll;

int n;
ll d[10001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	d[0] = 1;

	for (int i = 2; i <= n; i += 2)
	{
		for (int j = 0; j < i; j += 2)
		{
			d[i] += d[i - j - 2] * d[j];
			d[i] %= MOD;
		}
	}

	cout << d[n];

	return 0;
}