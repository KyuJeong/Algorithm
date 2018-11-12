#include <bits/stdc++.h>

using namespace std;

int n, k;
typedef vector <int> vi;
vi v, t;
vi ans;

bool search(int m)
{
	vector <int> vt = v;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (vt[i] - vt[i - 1] > m)
		{
			int tmp = vt[i];
			vt[i] = vt[i - 1] + m;
			cnt += tmp - vt[i];
			if (cnt > k) return false;
		}
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (vt[i] - vt[i + 1] > m)
		{
			int tmp = vt[i];
			vt[i] = vt[i + 1] + m;
			cnt += tmp - vt[i];
			if (cnt > k) return false;
		}
	}
	t = vt;
	return true;
}

void f()
{
	int l = 0;
	int r = 1000000000;
	int minn = r;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (search(m))
		{
			if (minn > m)
			{
				minn = m;
				ans = t;
			}
			r = m - 1;
		}
		else l = m + 1;
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	f();

	for (auto i : ans)
		cout << i << " ";

	return 0;
}