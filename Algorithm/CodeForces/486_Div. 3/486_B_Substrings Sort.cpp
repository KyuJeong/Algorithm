#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), [] (const string &s1, const string &s2)
	{
		return s1.size() < s2.size();
	});

	for (int i = 1; i < n; i++)
	{
		if (v[i].size() == v[i - 1].size())
		{
			if (v[i] != v[i - 1])
			{
				cout << "NO";
				return 0;
			}
				continue;
		}
		int len = v[i - 1].size();
		bool flag = false;
		for (int j = 0; j <= v[i].size() - len; j++)
		{
			string ss = v[i].substr(j, len);
			if (ss == v[i - 1])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES\n";
	for (auto i : v)
	{
		cout << i << "\n";
	}

	return 0;
}