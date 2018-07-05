#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[100001];
int cnt[100001];
bool check[100001];
bool check_f[100001];
ll kind;
ll ans;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
		if (!check[a[i]]) kind++;
		check[a[i]] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (--cnt[a[i]] == 0)
			kind--;
		if (check_f[a[i]])
			continue;
		check_f[a[i]] = true;
		ans += kind;
	}
	
	cout << ans;

	return 0;
}