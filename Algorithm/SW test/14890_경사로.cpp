#include <iostream>

using namespace std;

int N, L;
int G[100][100];
int ans;

int main()
{
	scanf("%d %d", &N, &L);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int pre = G[i][0];
		int pre_cnt = 0;
		int cnt = 0;
		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			if (pre == G[i][j])
				cnt++;
			// 뒤가 더 높은경우
			else if (pre == G[i][j] - 1)
			{
				if (cnt < L)
				{
					flag = false;
					break;
				}
				else
				{
					cnt = 1;
					pre = G[i][j];
				}
			}
			// 뒤가 더 낮은경우
			else if (pre == G[i][j] + 1)
			{
				pre = G[i][j];
				cnt = 0;
				for (int k = 0; k < L; k++)
				{
					// 범위를 넘어서는 경우
					if (j + k >= N)
					{
						flag = false;
						break;
					}
					if (pre == G[i][j + k])
					{
						cnt++;
						if (cnt == L)
						{
							cnt = 0;
							pre = G[i][j + k];
							j += k;
							break;
						}
					}
					if (pre != G[i][j + k])
					{
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			// 높이가 2 이상 차이나는 경우
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}

	for (int i = 0; i < N; i++)
	{
		int pre = G[0][i];
		int pre_cnt = 0;
		int cnt = 0;
		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			if (pre == G[j][i])
				cnt++;
			// 뒤가 더 높은경우
			else if (pre == G[j][i] - 1)
			{
				if (cnt < L)
				{
					flag = false;
					break;
				}
				else
				{
					cnt = 1;
					pre = G[j][i];
				}
			}
			// 뒤가 더 낮은경우
			else if (pre == G[j][i] + 1)
			{
				pre = G[j][i];
				cnt = 0;
				for (int k = 0; k < L; k++)
				{
					// 범위를 넘어서는 경우
					if (j + k >= N)
					{
						flag = false;
						break;
					}
					
					if (pre == G[j + k][i])
					{
						cnt++;
						if (cnt == L)
						{
							cnt = 0;
							pre = G[j + k][i];
							j += k;
							break;
						}
					}
					if (pre != G[j + k][i])
					{
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			// 높이가 2 이상 차이나는 경우
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}