#include <bits/stdc++.h>

using namespace std;

#define MAXN 100002
#define MOD 1000000007LL

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int n, m;
ll d[MAXN];
ll s[MAXN];
ll a[MAXN];
ll b[MAXN];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	int idx = max(n, m);
	if (n == 1 || m == 1) {
		d[1] = 1;
		s[1] = 1;
		d[2] = 2;
		s[2] = 2;
		for (int i = 3; i <= idx; i++) {
			s[i] = (d[i - 1] + s[i - 1]) % MOD;
			d[i] = s[i - 1];
		}
		ll ans = (s[idx] + d[idx]) % MOD;
		cout << ans;
	}
	else {
		d[2] = 2;
		s[2] = 2;
		for (int i = 3; i <= idx; i++) {
			s[i] = (d[i - 1] + s[i - 1]) % MOD;
			d[i] = s[i - 1];
		}
		ll ans = (s[idx] + d[idx] + 2LL) % MOD;
	
		idx = min(n, m);
		if (idx >= 3) {
			a[3] = 2;
			b[3] = 2;
			for (int i = 4; i <= idx; i++) {
				b[i] = (a[i - 1] + b[i - 1]) % MOD;
				a[i] = b[i - 1];
			}
			ll sum = (a[idx] + b[idx] - 2LL) % MOD;
			if (idx >= 4) {
				a[4] = 2;
				b[4] = 2;
				for (int i = 5; i <= idx; i++) {
					b[i] = (a[i - 1] + b[i - 1]) % MOD;
					a[i] = b[i - 1];
				}
				sum = (sum + a[idx] + b[idx] - 2LL) % MOD;
			}
			ans = (ans + sum) % MOD;
		}
		cout << ans;
	}

	return 0;
}