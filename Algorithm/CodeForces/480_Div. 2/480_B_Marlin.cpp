#include <bits/stdc++.h>

using namespace std;

int n, k;
char C[4][100];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = '.';
		}
	}

	if (k % 2 == 0)
	{
		for (int i = 1; i <= k; i ++)
		{
			C[1][i] = '#';
			C[2][i] = '#';
			k--;
		}
	}

	else
	{
		int start = n / 2;
		C[1][start] = '#';
		k--;
		for (int i = 1; i <= k; i++)
		{
			if (i == start)
				break;
			C[1][start - i] = '#';
			C[1][start + i] = '#';
			k -= 2;
		}

		if (k >= 2)
		{
			for (int i = 1; i <= k; i++)
			{
				C[2][i] = '#';
				C[2][n - 1 - i] = '#';
				k--;
			}
		}
	}

	cout << "YES\n";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << C[i][j];
		}
		cout << "\n";
	}

	return 0;
}