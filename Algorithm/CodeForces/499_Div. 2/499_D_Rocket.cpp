#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;

int main()
{
	int m, n;
	cin >> m >> n;
	vi seq(n);

	for (int i = 0; i < n; i++)
	{
		cout << 1 << "\n";
		cin >> seq[i];
		if (seq[i] == 0 || seq[i] == -2) return 0;

	}

	int res;
	int l = 1;
	int r = m;
	int cnt = 0;
	while (l != r)
	{
		int mid = (l + r + 1) / 2;
		cout << mid << "\n";

		cin >> res;
		if (res == 0 || res == -2) return 0;

		if (seq[cnt] == res)
			l = mid;
		else
			r = mid - 1;

		cnt = (cnt + 1) % n;
	}

}
