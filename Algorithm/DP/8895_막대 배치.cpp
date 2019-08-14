#include <bits/stdc++.h>

using namespace std;

int t, n, l, r;
long long d[21][21][21]; // ���� i���� ���� ��, ���ʿ��� j���� ���̰� �����ʿ��� k���� ���̴� ����� ��

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
				d[i][j][k] += d[i - 1][j - 1][k] + d[i - 1][j][k - 1]; // i��° ���븦 �� ���� ���� ���
				d[i][j][k] += d[i - 1][j][k] * (i - 2); // i��° ���븦 ���̿� ���� ���
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