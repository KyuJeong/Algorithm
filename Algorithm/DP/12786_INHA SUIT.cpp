#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int N, K;
int DP[101][22];
vector <int> hole[101];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= 21; j++)
			DP[i][j] = INF;
	}

	DP[0][1] = 0;

	for (int i = 1; i <= N; i++)
	{
		int M, H;
		cin >> M;
		while (M--)
		{
			cin >> H;
			hole[i].push_back(H);
		}

		for (auto j : hole[i])
		{
			if (j % 2 == 0)
				DP[i][j] = min({ DP[i - 1][j - 1],DP[i - 1][j],DP[i - 1][j + 1],DP[i - 1][j / 2] });
			else
				DP[i][j] = min({ DP[i - 1][j - 1],DP[i - 1][j],DP[i - 1][j + 1] });

			if (j == 20)
			{
				int tmp = *min_element(DP[i - 1] + 10, DP[i - 1] + 21);
				DP[i][j] = min(DP[i][j], tmp);
			}

			int min_T = *min_element(DP[i - 1] + 1, DP[i - 1] + 21) + 1;
			DP[i][j] = min(DP[i][j], min_T);
		}
	}

	int ans = *min_element(DP[N] + 1, DP[N] + 21);
	if (ans > K)
		cout << "-1";
	else
		cout << ans;
	
	return 0;
}