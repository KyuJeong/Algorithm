#include <bits/stdc++.h>

using namespace std;

#define MAXN 100002

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int t;
int n, m;
int D[MAXN];
int J[MAXN];
vector <int> n1, n2, m1, m2;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--) {
		cin >> n;
		n1.clear();
		n2.clear();
		m1.clear();
		m2.clear();
		for (int i = 0; i < n; i++) {
			cin >> D[i];
			if (D[i] & 1) n1.push_back(1);
			else n2.push_back(1);
		}
		cin >> m;
		vector <int> m1, m2;
		for (int i = 0; i < m; i++) {
			cin >> J[i];
			if (J[i] & 1) m1.push_back(1);
			else m2.push_back(1);
		}

		ll ans = (ll)n1.size() * (ll)m1.size();
		ans += (ll)n2.size() * (ll)m2.size();
 		
		cout << ans << "\n";
	}


	return 0;
}