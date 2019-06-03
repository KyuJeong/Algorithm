#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector <int> v;
int x;

bool search(int len)
{
	int cnt = -1;
	int pre = v[0];
	for (int i = 1; i <= m + 1; i++)
	{
		if (v[i] - pre >= len)
		{
			cnt++;
			pre = v[i];
		}
	}
	if (cnt >= x) return true;
	else return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	v.resize(m + 2);

	v[0] = 0; v[m + 1] = k;
	for (int i = 1; i <= m; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		int l = 1; int r = k;
		int ans;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (search(mid))
			{
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
		}
		cout << ans << "\n";
	}

	return 0;
}