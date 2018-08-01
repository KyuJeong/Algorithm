#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <ll> vl;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

vl arr;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	arr.resize(N * 2);
	for (int i = 0; i < N * 2; i++)
		cin >> arr[i];

	sort(all(arr));

	vl x(N);
	vl y(N);
	for (int i = 0; i < N; i++)
		x[i] = arr[i];
	for (int i = 0; i < N; i++)
		y[i] = arr[i + N];

	ll g = x[N - 1] - x[0];
	ll s = y[N - 1] - y[0];

	ll _min = 1e17;
	ll dif = arr[N * 2 - 1] - arr[0];

	for (int i = 0; i < N; i++)
	{
		ll cur = arr[i + N - 1] - arr[i];
		ll mul = dif * cur;
		if (_min > mul)
			_min = mul;
	}

	cout << _min;

	return 0;
}