#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int d[100001][2];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	d[0][0] = d[0][1] = arr[0];
	d[1][0] = d[1][1] = max(arr[0] + arr[1], arr[1]);
	for (int i = 2; i < n; i++) {
		d[i][0] = arr[i];

		if (d[i][0] < d[i - 1][0] + arr[i]) d[i][0] = d[i - 1][0] + arr[i];

		if (d[i - 1][1] < d[i - 2][0]) d[i][1] = d[i - 2][0] + arr[i];
		else d[i][1] = d[i - 1][1] + arr[i];

	}

	int ans = arr[0];
	for (int i = 0; i < n; i++) {
		if (ans < d[i][0]) ans = d[i][0];
		if (ans < d[i][1]) ans = d[i][1];
	}

	cout << ans;

	return 0;
}