#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, k, m;
int a[100001];
string s[100001];
string s2[100001];
map <string, int> mp;
long long ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= k; i++)
	{
		int tmp;
		cin >> tmp;
		int x[100001];
		int _min = 1e9;
		for (int j = 0; j < tmp; j++)
		{
			cin >> x[j];
			int idx = x[j];
			_min = min(_min, a[idx]);
		}

		for (int j = 0; j < tmp; j++)
		{
			int idx = x[j];
			a[idx] = _min;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		mp.insert({ s[i],a[i] });
	}

	for (int i = 1; i <= m; i++)
	{
		string str;
		cin >> str;
		ans += mp[str];
	}

	cout << ans;

	return 0;
}