#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, l, a;
	cin >> n >> l >> a;
	vector <pii> v;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].fst >> v[i].snd;
	}
	if (n == 0)
	{
		cout << l / a;
		return 0;
	}

	ll sum = 0;
	sum += v[0].fst / a;
	ll dif;
	ll pre = v[0].fst + v[0].snd;
	for (int i = 1; i < n; i++)
	{
		dif = v[i].fst - pre;
		sum += dif / a;
		pre = v[i].fst + v[i].snd;
	}

	dif = l - pre;
	sum += dif / a;
	cout << sum;
	return 0;
}