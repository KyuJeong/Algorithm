#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int n, x;
vi v, r;
bool idx[100001];
bool nxt[100001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> x;
	v.resize(n);
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (idx[v[i]])
		{
			cout << "0";
			return 0;
		}
		idx[v[i]] = true;
	}

	for (int i = 0; i < n; i++)
	{
		int cur = v[i] & x;
		if (cur > 100000) continue;

		if (v[i] != cur && idx[cur])
		{
			cout << "1";
			return 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cur = v[i] & x;
		if (cur > 100000) continue;

		if (nxt[cur])
		{
			cout << "2";
			return 0;
		}
		nxt[cur] = true;
	}

	cout << "-1";

	return 0;
}