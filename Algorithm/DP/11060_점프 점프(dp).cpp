#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int d[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		d[i] = 1e9;
	}

	d[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			if (i + j >= n) break;
			d[i + j] = min(d[i + j], d[i] + 1);
		}
	}

	if (d[n - 1] == 1e9) d[n - 1] = -1;
	cout << d[n - 1];

	return 0;
}