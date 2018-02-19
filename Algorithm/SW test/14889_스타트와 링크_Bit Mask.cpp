#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int G[21][21];
int min_dif = 1e9;

inline int Team(int mask)
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		if (mask & (1 << i)) cnt++;
	}

	return cnt;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	for (int i = 1; i < (1 << N); i++)
	{
		// 비트가 1인 자리의 수가 N / 2개여야함
		if (Team(i) != (N / 2))
			continue;

		int sum_start = 0;
		int sum_link = 0;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				for (int k = j + 1; k < N; k++)
				{
					if (i & (1 << k))
					{
						sum_start += G[j + 1][k + 1];
						sum_start += G[k + 1][j + 1];
					}
				}
			}
			else
			{
				for (int k = j + 1; k < N; k++)
				{
					if (!(i & (1 << k)))
					{
						sum_link += G[j + 1][k + 1];
						sum_link += G[k + 1][j + 1];
					}
				}
			}
		}
		int tmp = sum_start - sum_link;
		tmp = tmp > 0 ? tmp : tmp * (-1);
		min_dif = min(min_dif, tmp);
	}

	printf("%d", min_dif);

	return 0;
}