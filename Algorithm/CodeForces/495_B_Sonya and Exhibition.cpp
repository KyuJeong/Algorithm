#include <bits/stdc++.h>

using namespace std;

int n, m;
int l, r;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> l >> r;

	for (int i = 0; i < n; i++)
	{
		if (i & 1)
			cout << "0";
		else
			cout << "1";
	}


	return 0;
}