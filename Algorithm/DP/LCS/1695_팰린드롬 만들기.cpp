#include <bits/stdc++.h>

using namespace std;

int d[5001][5001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector <int> b = a;
	reverse(b.begin(), b.end());

	int _max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]);
			_max = max(_max, d[i + 1][j + 1]);
		}
	}

	cout << n - _max;

	return 0;
}