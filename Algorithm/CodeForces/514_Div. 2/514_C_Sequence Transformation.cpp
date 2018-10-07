#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

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

vi v;
vi ans;
bool chk[1010101];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n + 1);

	if (n == 1)
	{
		cout << "1";
		return 0;
	}
	if (n == 3)
	{
		cout << "1 1 3";
		return 0;
	}

	for (int i = 1; i <= n; i++)
		v[i] = i;

	int cnt = 0;
	int add = 2;
	while (cnt != n - 2)
	{
		for (int i = add / 2; i <= n; i += add)
		{
			chk[i] = true;
			ans.push_back(add / 2);
			cnt++;
			if (cnt == n - 2) break;
		}
		add *= 2;
	}

	vi tmp;
	for (int i = 1; i <= n; i++)
	{
		if (!chk[i]) tmp.push_back(i);
	}

	ans.push_back(gcd(tmp[0], tmp[1]));
	ans.push_back(tmp[1]);

	for (auto i : ans)
		cout << i << " " ;

	return 0;
}