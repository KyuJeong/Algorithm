#include <bits/stdc++.h>

using namespace std;

int n, x, y;
int len, fix;
int full;
int ans;

void solve(int seq, int cur)
{
	if (seq == full)
	{
		ans++; return;
	}

	if (cur == fix) solve(seq, cur + 1);
	else
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (i - cur - 1 < 0) break;
			if ((seq & (1 << i)) || seq & (1 << (i - cur - 1)))
				continue;
			solve(seq | (1 << i) | (1 << (i - cur - 1)), cur + 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> x >> y;

	len = n * 2;
	full = (1 << len) - 1;
	fix = y - x - 1;

	int seq = (1 << (len - x)) | (1 << (len - y));

	solve(seq, 1);

	cout << ans;

	return 0;
}