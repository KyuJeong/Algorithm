#include <iostream>

using namespace std;

int T;
long long DP[36][5];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;
	DP[1][3] = 1;

	for (int i = 2; i <= 35; i++)
	{
		DP[i][0] = DP[i - 2][0] + DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2] + DP[i - 1][3];
		DP[i][1] = DP[i - 1][0] + DP[i - 1][2]; // ���� 2�� ä�� ��
		DP[i][2] = DP[i - 1][0] + DP[i - 1][1];	// �Ʒ� 2�� ä�� ��
		DP[i][3] = DP[i - 1][0] + DP[i - 1][4];	// ��� 2�� ä�� ��
		DP[i][4] = DP[i - 1][3];	// �� �� 2�� ä�� ��
	}

	while (T--)
	{
		int N;
		cin >> N;

		cout << DP[N][0] << "\n";
	}

	return 0;
}