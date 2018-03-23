#include <iostream>

using namespace std;

int T;
int DP[101][100][2]; // DP[n][k][m] = ũ�� n, ���� ��Ʈ k��, m���� ���� �� ������ ����

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	DP[1][0][0] = 1;
	DP[1][0][1] = 1;

	for (int i = 2; i < 101; i++)
	{
		DP[i][0][0] = DP[i - 1][0][0] + DP[i - 1][0][1];
		DP[i][0][1] = DP[i - 1][0][0];
		for (int j = 1; j < i; j++)
		{
			DP[i][j][0] = DP[i - 1][j][0] + DP[i - 1][j][1];
			DP[i][j][1] = DP[i - 1][j][0] + DP[i - 1][j - 1][1];
		}
	}

	while (T--)
	{
		int n, k;

		cin >> n >> k;

		cout << DP[n][k][0] + DP[n][k][1] << "\n";
	}

	return 0;
}