#include <bits/stdc++.h>

using namespace std;

int G[5][20001];

string solve(int a[3])
{
	if (a[0] == 5)
	{
		if (a[1] == 2) return "0";
		if (a[2] == 4) return "6";
		return "8";
	}
	if (a[0] == 4)
	{
		if (a[2] == 5) return "9";
		return "2";
	}
	if (a[0] == 3)
	{
		if (a[1] == 3) return "3";
		return "4";
	}
	return "7";
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	n /= 5;
	string s;
	cin >> s;
	int t = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[t++] == '#')
				G[i][j] = 1;
		}
	}

	int cnt[3] = { 0 };
	int idx = 0;
	string ans;
	for (int i = 0; i < n; i++)
	{
		int one = 0;
		for (int j = 0; j < 5; j++)
		{
			if (G[j][i] == 1) one++;
		}

		if (one == 0)
		{
			if (idx == 1) ans += "1";
			idx = 0;
			cnt[0] = cnt[1] = cnt[2] = 0;
			continue;
		}
		cnt[idx++] = one;

		if (idx == 3)
		{
			string tmp = solve(cnt);
			if (tmp == "2" && G[1][i] == 0) tmp = "5";
			ans += tmp;
			idx = 0;
			cnt[0] = cnt[1] = cnt[2] = 0;
		}
	}

	if (cnt[0] == 5) ans += "1";

	cout << ans;

	return 0;
}