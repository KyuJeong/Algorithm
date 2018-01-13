#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int tmp;	// 자두 떨어지는 위치
int DP[1001][31][3];	// T초에 W번 움직였고 k 위치에 있을 때 받을 수 있는 자두의 최대 개수
int ans;

int main()
{
	scanf("%d %d", &T, &W);

	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &tmp);
		if (tmp == 1)
			DP[i][0][1] = DP[i - 1][0][1] + 1;

		for (int j = 1; j <= W; j++)
		{
			if (i < j)
				break;
			if (tmp == 1)
			{
				DP[i][j][1] = max(DP[i - 1][j][1], DP[i - 1][j - 1][2]) + 1;
				DP[i][j][2] = max(DP[i - 1][j - 1][1], DP[i - 1][j][2]);
			}
			else
			{
				DP[i][j][1] = max(DP[i - 1][j][1], DP[i - 1][j - 1][2]);
				DP[i][j][2] = max(DP[i - 1][j - 1][1], DP[i - 1][j][2]) + 1;
			}
		}
	}
		
	for (int i = 0; i <= W; i++)
	{
		ans = max(ans, DP[T][i][1]);
		ans = max(ans, DP[T][i][2]);
	}

	cout << ans;

	return 0;
}