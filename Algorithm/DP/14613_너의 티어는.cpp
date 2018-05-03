#include <bits/stdc++.h>

using namespace std;

double w, l, d;

double tier[5];
double DP[21][3001]; // DP[N][M] = N번 경기했을때 점수가 M일 확률

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> w >> l >> d;

	DP[0][2000] = 1;

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1000; j <= 3000; j++)
		{
			DP[i][j - 50] += DP[i - 1][j] * l;
			DP[i][j + 50] += DP[i - 1][j] * w;
			DP[i][j] += DP[i - 1][j] * d;
		}
	}

	for (int i = 1000; i <= 3000; i += 50)
	{
		if (i < 1500) tier[0] += DP[20][i];
		else if (i < 2000) tier[1] += DP[20][i];
		else if (i < 2500) tier[2] += DP[20][i];
		else if (i < 3000) tier[3] += DP[20][i];
		else tier[4] += DP[20][i];
	}


	for (int i = 0; i <= 4; i++)
	{
		printf("%.8lf\n", tier[i]);
	}

	return 0;
}