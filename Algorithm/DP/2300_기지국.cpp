#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int n;
vector <pair <int, int>> v(1);

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x,abs(y) });
	}

	vector <int> dp(n + 1, 1e9); // 0 ~ i번 건물까지 연결할 때 설치비용의 최솟값
	sort(v.begin() + 1, v.end());
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int up = 0;
		for (int j = i; j >= 1; j--)
		{
			up = max(up, v[j].se);
			int area = max(v[i].fi - v[j].fi, up * 2);
			if (dp[i] > dp[j - 1] + area) dp[i] = dp[j - 1] + area;
		}
	}

	cout << dp[n];

	return 0;
}