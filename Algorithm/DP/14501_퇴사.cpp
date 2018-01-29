#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[16], P[16];
int DP[16];
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
		if (i + T[i] - 1 <= N)
			DP[i] = P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (i + T[i] - 1 > N)
			continue;
		for (int j = 1; j < i; j++)
		{
			if (j + T[j] - 1 < i)
				DP[i] = max(DP[i], DP[j] + P[i]);
		}
		ans = max(ans, DP[i]);
	}

	cout << ans;

	return 0;
}