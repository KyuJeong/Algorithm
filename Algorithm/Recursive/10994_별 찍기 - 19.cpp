#include <bits/stdc++.h>

using namespace std;

char G[400][400];

void solve(int len, int sy, int sx)
{
	if (len == 1)
	{
		G[sy][sx] = '*';
		return;
	}

	for (int i = 0; i < len; i++)
	{
		G[sy][sx + i] = '*';
		G[sy + i][sx] = '*';
		G[sy + len - 1][sx + i] = '*';
		G[sy + i][sx + len - 1] = '*';
	}

	solve(len - 4, sy + 2, sx + 2);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int l = 4 * n - 3;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l; j++)
			G[i][j] = ' ';

	solve(l, 0, 0);

	for (int i = 0; i < l; i++)
		cout << G[i] << "\n";

	return 0;
}