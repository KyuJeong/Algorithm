#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

string tmp, s, p;
vi pi, ans;

void getPi()
{
	int m = p.size();
	pi.resize(m);
	int j = 0;
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

bool kmp()
{
	getPi();
	int n = s.size();
	int m = p.size();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				return true;
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tmp;

	for (auto i : tmp)
		if (i >= 'A') s += i;

	cin >> p;

	bool ans = kmp();

	if (ans)
		cout << "1";
	else
		cout << "0";

	return 0;
}