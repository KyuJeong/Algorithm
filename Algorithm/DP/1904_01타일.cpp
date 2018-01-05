#include <iostream>

#define MOD 15746

using namespace std;

int N;
int DP[3];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		DP[3] = (DP[1] + DP[2]) % MOD;
		DP[1] = DP[2];
		DP[2] = DP[3];
	}

	cout << DP[3];

	return 0;
}