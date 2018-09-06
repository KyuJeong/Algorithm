#include <bits/stdc++.h>

using namespace std;

string bigSum(string a, string b)
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

int n;
string dp[251];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	dp[0] = "1";
	dp[1] = "1";
	for (int i = 2; i <= 250; i++)
	{
		dp[i] = bigSum(dp[i], dp[i - 1]);
		dp[i] = bigSum(dp[i], dp[i - 2]);
		dp[i] = bigSum(dp[i], dp[i - 2]);
	}

	while (cin >> n)
		cout << dp[n] << "\n";

	return 0;
}