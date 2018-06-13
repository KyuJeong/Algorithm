#include <bits/stdc++.h>

using namespace std;

int G[1001][1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, a;

	cin >> N >> a;

	int t = 1;
	int num = N * N;

	for (int i = N; i >= 1; i -= 2)
	{
		for (int j = t; j <= t + i - 1; j++)
			G[j][t] = num--;

		for (int j = t + 1; j <= N - t + 1; j++)
			G[N - t + 1][j] = num--;

		for (int j = N - t; j >= t; j--)
			G[j][N - t + 1] = num--;

		for (int j = N - t; j >= t + 1; j--)
			G[t][j] = num--;

		t++;
	}

	int y, x;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << G[i][j] << " ";
			if (G[i][j] == a)
			{
				y = i;
				x = j;
			}
		}
		cout << "\n";
	}

	cout << y << " " << x;

	return 0;
}