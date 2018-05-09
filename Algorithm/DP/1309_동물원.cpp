#include <iostream>
using namespace std;

#define MOD 9901;

int N;
int DP[3] = { 3,7 };
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i < N; i++)
	{
		DP[2] = (DP[0] + 2 * DP[1]) % MOD;
		DP[0] = DP[1]; DP[1] = DP[2];
	}

	cout << DP[0];

	return 0;
}