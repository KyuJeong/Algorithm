#include <iostream>
using namespace std;

long long int DP[101];
int T, N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 5];
	}
	while (T--)
	{
		cin >> N;

		cout << DP[N] << "\n";
	}


	return 0;
}