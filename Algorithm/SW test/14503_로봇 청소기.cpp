#include <iostream>

using namespace std;

#define MOD 4

int N, M;
int r, c, d;
int G[50][50];
int my[] = { -1,0,1,0 };
int mx[] = { 0,1,0,-1 };
int ans;

void Clean()
{	
	int cy = r;
	int cx = c;
	while (1)
	{
		bool clean_flag = false;
		G[cy][cx] = -1;	// 현재 위치 청소
		ans++;
		int num = 0;
		while(1)
		{
			d += 3;	// 왼쪽부터 탐색 진행
			d %= MOD;
			int ny = cy + my[d];
			int nx = cx + mx[d];
			num++;

			if (G[ny][nx] == 0)	// 2-1
			{
				cy = ny;
				cx = nx;
				clean_flag = true;
				break;
			}
			else // 2-2
			{
				if (num != 4)
					continue;
				else
				{
					cy -= my[d];
					cx -= mx[d];
					if (G[cy][cx] == 1) // 2-4 (작동 멈춤)
					{
						clean_flag = false;
						break;
					}
					num = 0;
					continue; // 2-3
				}
			}
		}
		if (!clean_flag)
			break;
	}
}

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	Clean();

	printf("%d", ans);

	return 0;
}