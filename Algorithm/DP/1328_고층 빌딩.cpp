#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long DP[102][102][102]; // DP[N][L][R] =  빌딩이 N개이고 왼쪽에서 L개, 오른쪽에서 R개 보일 때 가능한 빌딩 순서의 경우의 수
int N, L, R;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	DP[1][1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				DP[i + 1][j][k] = (DP[i + 1][j][k] + (DP[i][j][k] * (i - 1))) % MOD;
				DP[i + 1][j + 1][k] = (DP[i + 1][j + 1][k] + DP[i][j][k]) % MOD;
				DP[i + 1][j][k + 1] = (DP[i + 1][j][k + 1] + DP[i][j][k]) % MOD;
			}
		}
	}

	cout << DP[N][L][R];

	return 0;
}