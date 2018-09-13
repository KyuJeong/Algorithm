#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int cnt[26];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	for (auto i : s)
		cnt[i - 'A']++;

	int kind = 0;
	int _min = 1e9;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == 0) continue;
		kind++;
		_min = min(_min, cnt[i]);
	}

	if (kind < k)
		cout << "0";
	else
		cout << _min * k;

	return 0;
}