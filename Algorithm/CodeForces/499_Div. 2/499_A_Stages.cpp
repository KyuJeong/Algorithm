#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	sort(s.begin(), s.end());
	int ans = 0;

	int cnt = 1;
	ans += s[0] - 'a' + 1;
	int pre = s[0];
	for (int i = 1; i < n; i++)
	{
		if (cnt == k)
			break;
		if (s[i] - pre <= 1) continue;
		ans += s[i] - 'a' + 1;
		
		pre = s[i];
		cnt++;
	}

	if (cnt < k)
		cout << "-1";
	else
		cout << ans;

	return 0;
}
