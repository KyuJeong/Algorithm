#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100001];
int ans;

int gcd(int u, int v)
{
	while (v != 0)
	{
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int g = arr[2] - arr[1];
	for (int i = 3; i <= N; i++)
		g = gcd(arr[i] - arr[i - 1], g);

	for (int i = 2; i <= N; i++)
		ans += (arr[i] - arr[i-1]) / g - 1;

	cout << ans;

	return 0;
}