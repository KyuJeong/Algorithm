#include <iostream>
using namespace std;

#define INF 10000000

int N, M;
int G[101][101];
int temp1, temp2;
int kevin_bacon[101];
int min_index;
int min_value;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			G[i][j] = INF;
			if (i == j)
				G[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		G[temp1][temp2] = 1;
		G[temp2][temp1] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (G[j][k] > G[j][i] + G[i][k])
					G[j][k] = G[j][i] + G[i][k];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			kevin_bacon[i] += G[i][j];
		}
	}

	min_value = INF;

	for (int i = N; i >= 1; i--)
	{
		if (min_value >= kevin_bacon[i])
		{
			min_value = kevin_bacon[i];
			min_index = i;
		}
	}

	cout << min_index;

	return 0;
}