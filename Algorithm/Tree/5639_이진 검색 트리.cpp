#include <bits/stdc++.h>

using namespace std;

int arr[10101];
int x;

void f(int l, int r)
{
	if (l >= r) return;

	int m = l + 1;
	while (m < r && arr[m] < arr[l]) m++;
	f(l + 1, m);
	f(m, r);
	cout << arr[l] << "\n";
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (cin >> arr[x++]);

	f(0, x - 1);

	return 0;
}