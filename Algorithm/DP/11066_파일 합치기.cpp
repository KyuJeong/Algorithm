#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 99999999

int T, K, tmp;
int array_sum[501];
int DP[501][501];
int arr[501];

inline void init()
{
	memset(DP, 0, sizeof(DP));
	memset(array_sum, 0, sizeof(array_sum));
}

inline int CombinePart(int start, int end)
{
	if (start == end) // 합치지 않을 때는 비용 더하지 않음
		return 0;

	if (DP[start][end])	// start ~ end 비용이 이미 구해져있을 때
		return DP[start][end];
	
	if (start + 1 == end)
		return DP[start][end] = arr[start] + arr[end];

	int sum = INF;

	for (int i = start; i < end; i++)
	{
		// 합치는 비용 계산하고 개별 비용 다 더해줌
		int combine_cost = CombinePart(start, i) + CombinePart(i + 1, end) + array_sum[end] - array_sum[start - 1];

		// 최솟값 찾기
		sum = min(sum, combine_cost);
	}

	return DP[start][end] = sum;
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &K);

		init();

		for (int i = 1; i <= K; i++)
		{
			scanf("%d", &arr[i]);
			DP[i][i] = arr[i];
			array_sum[i] = array_sum[i - 1] + arr[i];
		}

		printf("%d\n", CombinePart(1, K));
	}

	return 0;
}