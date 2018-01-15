#include <iostream>
#include <vector>

using namespace std;

int N;
int G[1001][1001];
int degree[1001];

void DFS(int x)
{
	for (int i = 1; i <= N; i++)
	{
		while (G[x][i])
		{
			G[x][i]--;
			G[i][x]--;

			DFS(i);

			printf("%d ", i);
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &G[i][j]);
			if (G[i][j] != 0)
				degree[i] += G[i][j];
		}
		if (degree[i] & 1)
		{
			printf("-1");
			return 0;
		}
	}

	DFS(1);
	printf("1");

	return 0;
}