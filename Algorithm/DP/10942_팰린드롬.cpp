#include <iostream>
#include <vector>

using namespace std;

#define MAX 2001

int DP[MAX][MAX];
vector <int> arr(MAX);
int N, M, S, E;
 
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++)
		{
			if (i == 0)		// 한 글자
				DP[j][j] = 1;
			else if (i == 1)	// 두 글자
			{
				if (arr[j] == arr[j + 1])
					DP[j][j + 1] = 1;
			}
			else    // 세 글자 이상일 때
			{
				if (arr[j] == arr[j + i] && DP[j + 1][j + i - 1] == 1)
					DP[j][j + i] = 1;
			}
		}
	}

	scanf("%d", &M);

	while (M--)
	{
		scanf("%d %d", &S, &E);
		printf("%d\n", DP[S][E]);
	}

	return 0;
}