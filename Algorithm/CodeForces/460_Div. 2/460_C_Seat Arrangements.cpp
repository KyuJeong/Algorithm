#include <iostream>

using namespace std;

int n, m, k;
char G[2001][2001];
long long seat_i, seat_j;
long long ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> G[i][j];
				if(G[i][j] == '.')
					ans++;
			}
		}

		cout << ans;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		int pre = -1;
		int cur = -1;
		int dist = -1;
		for (int j = 0; j < m; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '*')
			{
				cur = j;
				dist = cur - pre;
				if (dist > k)
					seat_j += dist - k;
				pre = cur;
			}
		}
		dist = m - pre;
		if (dist > k)
			seat_j += dist - k;
	}

	for (int j = 0; j < m; j++)
	{
		int pre = -1;
		int cur = -1;
		int dist = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> G[i][j];
			if (G[i][j] == '*')
			{
				cur = i;
				dist = cur - pre;
				if (dist > k)
					seat_i += dist - k;
				pre = cur;
			}
		}
		dist = n - pre;
		if (dist > k)
			seat_j += dist - k;
	}

	ans = seat_i + seat_j;
	cout << ans;
	return 0;
}