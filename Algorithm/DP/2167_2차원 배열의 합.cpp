#include <iostream>

using namespace std;

int N, M, K;
int u, v, x, y;
int arr[301][301];

int main()
{

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	}

	cin >> K;
	while (K--)
	{
		scanf("%d %d %d %d", &u, &v, &x, &y);
		int ans = 0;

		for (int i = u; i <= x; i++)
			ans += (arr[i][y] - arr[i][v - 1]);

		printf("%d\n", ans);
	}

	return 0;
}