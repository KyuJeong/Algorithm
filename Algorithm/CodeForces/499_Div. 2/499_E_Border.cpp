#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	ll tmp, n;
	if (a < b)
		swap(a, b);

	while (b != 0) {
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

ll n, k;
ll g;
vector <ll> v;

int main() 
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	g = k;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		g = gcd(g, x);
	}

	for (int i = 0; i < k; i += g)
		v.push_back(i);

	cout << v.size() << "\n";
	for (auto i : v)
		cout << i << " ";

	return 0;
}
