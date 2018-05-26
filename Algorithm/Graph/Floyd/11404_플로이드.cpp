#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

typedef long long ll;

int G[101][101];
int N, M;
int temp1, temp2, temp3;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
				G[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		G[temp1][temp2] = min(G[temp1][temp2], temp3);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (G[j][i] == INF)
				continue;
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
			if (G[i][j] == INF)
				G[i][j] = 0;
			cout << G[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}