#include <bits/stdc++.h>

using namespace std;

#define MOD 10007

int DP[1001][1001];
string s;
int ans;
int len;

int solve(int i, int j)
{
	int &ret = DP[i][j];
	if (ret != -1)
		return ret;

	if (i == j)
		return ret = 1;
	if (i > j)
		return ret = 0;
	
	ret = 0;

	ret = solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1) + MOD;

	if (s[i] == s[j])
		ret += solve(i + 1, j - 1) + 1;

	ret %= MOD;

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;
	
	memset(DP, -1, sizeof(DP));

	len = s.size() - 1;

	int ans = solve(0, len);

	cout << ans;

	return 0;
}