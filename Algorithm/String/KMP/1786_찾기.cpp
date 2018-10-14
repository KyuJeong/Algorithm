#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

string s, p;
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

void kmp()
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
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	getline(cin, s);
	getline(cin, p);

	kmp();

	cout << ans.size() << "\n";

	for (auto i : ans)
		cout << i + 1 << " ";

	return 0;
}