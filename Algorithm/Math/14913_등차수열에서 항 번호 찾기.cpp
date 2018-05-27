#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, d, k;

	cin >> a >> d >> k;

	int idx = 1;

	while (1)
	{
		if (a == k)
		{
			cout << idx;
			return 0;
		}
		a += d;
		idx++;

		if (d < 0 && a < k)
			break;
		if (d > 0 && a > k)
			break;
	}

	cout << "X";

	return 0;
}