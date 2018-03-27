#include <iostream>

using namespace std;

#define MOD 1000000

int N;
int DP[1001][2][3];
/*
DP[N][M][L] = N�� °���� ������ M�� �ϰ�, N�Ͽ� ���°� L�� ��
L => 0 : �⼮ / 1 : ���� / 2 : �Ἦ
*/


int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[0][0][0] = 1;
	DP[0][0][2] = 1;
	DP[1][0][0] = 1;
	DP[1][1][1] = 1;
	DP[1][0][2] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[i][0][0] = (DP[i - 1][0][0] + DP[i - 1][0][2]) % MOD;
		DP[i][0][2] = (DP[i - 1][0][0] + DP[i - 2][0][0]) % MOD;
		DP[i][1][0] = (DP[i - 1][1][0] + DP[i - 1][1][1] + DP[i - 1][1][2]) % MOD;
		DP[i][1][1] = (DP[i - 1][0][0] + DP[i - 1][0][2]) % MOD;
		DP[i][1][2] = (DP[i - 2][1][0] + DP[i - 2][1][1] + DP[i - 1][1][0] + DP[i - 1][1][1]) % MOD;
	}

	int ans = (DP[N][0][0] + DP[N][0][2] + DP[N][1][0] + DP[N][1][1] + DP[N][1][2]) % MOD;

	cout << ans;

	return 0;
}