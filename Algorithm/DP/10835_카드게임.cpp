#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int A[2002];
int B[2002];
int DP[2002][2002];
int ans = 0;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> B[i];
	}

	memset(DP, -10, sizeof(DP));

	DP[0][0] = 0;

	for (int i = 1; i <= N + 1; i++)
	{
		for (int j = 1; j <= N + 1; j++)
		{
			if (A[i] > B[j - 1])
				DP[i][j] = max({ DP[i - 1][j - 1] ,DP[i - 1][j],DP[i][j - 1] + B[j - 1] });
			else
			{
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
				if (DP[i][j] == 0)
					continue;
			}
			ans = max(ans, DP[i][j]);
		}

	}

	cout << ans;

	return 0;
}