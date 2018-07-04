#include <bits/stdc++.h>

using namespace std;

#define MAX 1025

int N, M;
int sum[MAX][MAX];
int r1, r2, c1, c2;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	int t;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> t;
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + t;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		int ans = 0;

		ans += sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
	
		cout << ans << "\n";
	}

	return 0;
}