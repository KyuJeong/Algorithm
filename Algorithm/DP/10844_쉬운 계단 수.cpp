#include <iostream>
using namespace std;

long long int DP[101][10];
long long int sum;
int N;

int main()
{

	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		DP[i][0] = DP[i - 1][1];
		for (int j = 1; j <= 8; j++)
		{
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
		DP[i][9] = DP[i - 1][8];
	}

	for (int i = 0; i <= 9; i++)
	{
		sum += DP[N][i];
	}

	cout << sum % 1000000000;

	return 0;
}