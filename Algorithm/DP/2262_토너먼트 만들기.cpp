#include <bits/stdc++.h>

using namespace std;

int N;
int arr[257];
int dp[257][257];
int t[257][257];

inline int solve(int l, int r)
{
	if (l == r) return 0;
	int& ret = dp[l][r];
	if (l + 1 == r) ret = abs(arr[l] - arr[r]);
	if (ret != -1) return ret;

	ret = 1e9;

	for (int i = l; i < r; i++)
		ret = min(ret, solve(l, i) + solve(i + 1, r) + abs(t[l][i] - t[i + 1][r]));
	
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++)
	{
		t[i][i] = arr[i];
		for (int j = i + 1; j <= N; j++)
			t[i][j] = min(t[i][j - 1], arr[j]);
	}

	int ans = solve(1, N);

	cout << ans;

	return 0;
}