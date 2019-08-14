#include <bits/stdc++.h>

using namespace std;

int t, n, l, r;
long long d[21][21][21]; // 막대 i개를 놨을 때, 왼쪽에서 j개가 보이고 오른쪽에서 k개가 보이는 경우의 수

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	d[1][1][1] = d[2][1][2] = d[2][2][1] = 1;

	for (int i = 3; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			for (int k = 1; k <= 20; k++)
			{
				d[i][j][k] += d[i - 1][j - 1][k] + d[i - 1][j][k - 1]; // i번째 막대를 양 끝에 놓는 경우
				d[i][j][k] += d[i - 1][j][k] * (i - 2); // i번째 막대를 사이에 놓는 경우
			}
		}
	}

	cin >> t;
	while (t--)
	{
		cin >> n >> l >> r;
		cout << d[n][l][r] << "\n";
	}

	return 0;
}