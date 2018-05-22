#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> a >> b;

	if (a > b)
		swap(a, b);

	int cnt = 1;

	while (1)
	{
		if (a % 2 == 1 && a == b - 1)
			break;

		if (a % 2 == 0)
			a /= 2;
		else
			a = a / 2 + 1;
		if (b % 2 == 0)
			b /= 2;
		else
			b = b / 2 + 1;

		cnt++;
	}

	cout << cnt;

	return 0;
}