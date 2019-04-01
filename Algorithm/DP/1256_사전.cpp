#include <bits/stdc++.h>

using namespace std;

int arr[201][101];

int calc(int a, int b)
{
	if (arr[a][b] > 0) return arr[a][b];

	if (b == 0 || a == b) return arr[a][b] = 1;

	return arr[a][b] = min(calc(a - 1, b - 1) + calc(a - 1, b), 1000000000);
}

int solve(int n, int m, int k)
{
	if (n == 0)
	{
		for (int i = 0; i < m; i++)
			cout << "z";
		return 0;
	}

	if (m == 0)
	{
		for (int i = 0; i < n; i++)
			cout << "a";
		return 0;
	}

	int tmp = calc(n + m - 1, m);
	if (k <= tmp)
	{
		cout << "a";
		solve(n - 1, m, k);
	}
	else
	{
		cout << "z";
		solve(n, m - 1, k - tmp);
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	if (calc(n + m, n) < k)
	{
		cout << "-1";
		return 0;
	}

	solve(n, m, k);

	return 0;
}