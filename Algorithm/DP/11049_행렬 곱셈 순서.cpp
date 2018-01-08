#include <iostream>
#include <algorithm>

using namespace std;

#define INF 999999999

int N;
int mtx[501][2];
int DP[501][501];	// [col]부터 [row]까지 행렬 곱의 최솟값

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> mtx[i][0] >> mtx[i][1];
	}

	if (N == 1) 
	{
		cout << mtx[1][0] * mtx[1][1];
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			int tmp = INF;
			for (int k = 0; k < i; k++)
			{
				int mul_matrix = mtx[j][0] * mtx[j + k][1] * mtx[j + i][1];
				DP[j][j+i] = min(tmp, DP[j][j + k] + DP[j + k + 1][j + i] + mul_matrix);
				tmp = DP[j][j + i];
			}
		}
	}

	cout << DP[1][N];

	return 0;
}