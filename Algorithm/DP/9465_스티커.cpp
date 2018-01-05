#include <iostream>
#include <algorithm>
using namespace std;

int Stk[100000][2];
int DP[100000][3];
int selected_stk;

int main()
{
	std::ios::sync_with_stdio(false);

	int T;

	cin >> T;
	int n;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> Stk[j][0];
		}

		for (int j = 0; j < n; j++)
		{
			cin >> Stk[j][1];
		}

		DP[0][0] = Stk[0][0];
		DP[0][1] = Stk[0][1];
		DP[0][2] = 0;

		for (int j = 1; j < n; j++)
		{
			DP[j][0] = max(DP[j - 1][1], DP[j - 1][2]) + Stk[j][0];
			DP[j][1] = max(DP[j - 1][0], DP[j - 1][2]) + Stk[j][1];
			DP[j][2] = max(DP[j - 1][0], DP[j - 1][1]);
		}

		cout << max(DP[n - 1][0], DP[n - 1][1]) << "\n";

	}


	return 0;
}