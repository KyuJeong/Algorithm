#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string DP[101][101];

string BigSum(string a, string b)
{
	string s;
	if (a.size() < b.size())
		swap(a, b);

	int j = b.size() - 1;
	char tmp;

	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (j >= 0)
			tmp = a[i] + b[j] - '0';
		else
			tmp = a[i];

		s += tmp;

		j--;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > '9')
		{
			s[i] -= 10;
			if (i == s.size() - 1)
				s += '1';
			else
				s[i + 1] += 1;
		}
	}

	reverse(s.begin(), s.end());

	return s;
}

string Solve(int n, int m)
{
	string &ret = DP[n][m];

	if (DP[n][m] != "")
		return ret;

	if (m == 0 || n == m)
	{
		ret = "1";
		return ret;
	}

	ret = BigSum(Solve(n - 1, m - 1), Solve(n - 1, m));
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	if (m > (n - m))
		m = n - m;

	string ans = Solve(n, m);

	cout << ans;

	return 0;
}