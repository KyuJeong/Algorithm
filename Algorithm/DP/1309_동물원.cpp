#include <iostream>
using namespace std;

#define MOD 9901;

int N;
int DP[2][3];
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i <= 2; i++)
		DP[0][i] = 1;

	for (int i = 1; i < N; i++)
	{
		DP[1][0] = (DP[0][0] + DP[0][1] + DP[0][2]) % MOD;
		DP[1][1] = (DP[0][0] + DP[0][2]) % MOD;
		DP[1][2] = (DP[0][0] + DP[0][1]) % MOD;
		DP[0][0] = DP[1][0];
		DP[0][1] = DP[1][1];
		DP[0][2] = DP[1][2];
	}

	for (int i = 0; i <= 2; i++)
		ans += DP[1][i];

	cout << ans % MOD;

	return 0;
}