#include <iostream>

using namespace std;

int n;
int DP[21];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 2] + DP[i - 1];
	}

	cout << DP[n];

	return 0;
}