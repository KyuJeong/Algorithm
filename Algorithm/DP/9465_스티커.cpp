#include <iostream>
#include <algorithm>
using namespace std;

int stkr[100000][2];
int DP[2][3];
int T, n;

int main()
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &stkr[j][0]);
		}

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &stkr[j][1]);
		}

		DP[0][0] = stkr[0][0];
		DP[0][1] = stkr[0][1];
		DP[0][2] = 0;

		for (int j = 1; j < n; j++)
		{
			DP[1][0] = max(DP[0][1], DP[0][2]) + stkr[j][0];
			DP[1][1] = max(DP[0][0], DP[0][2]) + stkr[j][1];
			DP[1][2] = max(DP[0][0], DP[0][1]);

			DP[0][0] = DP[1][0];
			DP[0][1] = DP[1][1];
			DP[0][2] = DP[1][2];
		}

		printf("%d\n", max(DP[0][0], DP[0][1]));
	}


	return 0;
}