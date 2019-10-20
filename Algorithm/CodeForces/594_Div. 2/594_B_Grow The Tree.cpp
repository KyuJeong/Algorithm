#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int n;
vll v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(all(v));
	int sz = v.size();

	ll garo = 0;
	ll sero = 0;
	for (int i = 0; i < sz / 2; i++) {
		garo += v[i];
	}

	for (int i = sz / 2; i < sz; i++) {
		sero += v[i];
	}

	ll ans = garo * garo + sero * sero;
	cout << ans;

	return 0;
}