#include <iostream>

using namespace std;

#define MOD 1000000

long long N;
long long DP[3];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	N %= (15 * MOD) / 10;

	DP[1] = 1;
	DP[2] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[2] = (DP[0] + DP[1]) % MOD;
		DP[0] = DP[1];
		DP[1] = DP[2];
	}

	cout << DP[2];

	return 0;
}