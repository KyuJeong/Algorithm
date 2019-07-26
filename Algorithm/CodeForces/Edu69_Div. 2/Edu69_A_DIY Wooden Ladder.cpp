#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int tc;
vi v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());

		int sero = v[n - 2];
		int ans = min(sero - 1, n - 2);
		cout << ans << "\n";
	}

	return 0;
}
