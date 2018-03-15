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
		DP[i][1] = DP[i - 1][0] + DP[i - 1][2]; // 위의 2개 채울 때
		DP[i][2] = DP[i - 1][0] + DP[i - 1][1];	// 아래 2개 채울 때
		DP[i][3] = DP[i - 1][0] + DP[i - 1][4];	// 가운데 2개 채울 때
		DP[i][4] = DP[i - 1][3];	// 양 끝 2개 채울 때
	}

	while (T--)
	{
		int N;
		cin >> N;

		cout << DP[N][0] << "\n";
	}

	return 0;
}