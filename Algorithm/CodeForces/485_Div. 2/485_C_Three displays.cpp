#include <bits/stdc++.h>

using namespace std;

#define INF 1e16

typedef long long ll;

ll N;
ll s[3001];
ll c[3001];
ll DP[3001][4];
ll _min = INF;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> s[i];
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
			DP[i][j] = INF;
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		DP[i][1] = c[i];
	}


	DP[1][1] = c[1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (s[j] < s[i])
			{
				for (int k = 1; k <= min(3, i); k++)
				{
					/*DP[i][1] = max(DP[i][1], DP[j][0] + c[i]);
					DP[i][2] = max(DP[i][2], DP[j][1] + c[i]);
					DP[i][3] = max(DP[i][3], DP[j][2] + c[i]);*/
					DP[i][k] = min(DP[i][k], DP[j][k - 1] + c[i]);
				}
			}
		}
	}

	for (int i = 3; i <= N; i++)
	{
		_min = min(_min, DP[i][3]);
	}

	if (_min == INF)
		cout << "-1";
	else
		cout << _min;

	return 0;
}