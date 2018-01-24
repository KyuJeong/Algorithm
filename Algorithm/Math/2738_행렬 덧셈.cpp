#include <iostream>

using namespace std;

int N, M;
int A[101][101];
int tmp;

int main()
{
	std::ios::sync_with_stdio(false);
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &tmp);
			printf("%d ", A[i][j] + tmp);
		}
		printf("\n");
	}

	return 0;
}