#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	ll n, d;

	cin >> n >> d;

	ll arr[101];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 2;

	d *= 2;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[i - 1] == d)
			ans++;
		else if (arr[i] - arr[i - 1] > d)
			ans += 2;
	}

	cout << ans;

	return 0;
}