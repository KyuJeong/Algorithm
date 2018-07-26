#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int N, M;
vector <pii> v;
int dp[1001][2];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	v.resize(M);
	for (int i = 0; i < M; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), [](const pii &p1, const pii &p2)
	{
		return p1.second < p2.second;
	});

	for (int i = 0; i < M; i++)
	{
		dp[i][0] = v[i].first - 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i].first > v[j].second)
			{
				int tmp = max(dp[j][0], v[i].first - v[j].second - 1);
				dp[i][0] = min(dp[i][0], tmp);
			}
		}
		dp[i][1] = N - v[i].second;
	}

	int ans = 1e9;
	for (int i = 0; i < M; i++)
	{
		int tmp = max(dp[i][0], dp[i][1]);
		ans = min(ans, tmp);
	}

	cout << ans;

	return 0;
}