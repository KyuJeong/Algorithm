#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int wheel[5][8];
int K;
int in_num, in_dir;
int nw[] = { -1,1 };
int score;

void Spin()
{
	bool check[5] = { false };	// 지나친 톱니바퀴인지
	int final_dir[5];	// 돌릴 방향을 저장해놨다가 마지막에 돌림

	queue <pii> q;

	q.push({ in_num, in_dir });

	while (!q.empty())
	{
		int num = q.front().first;
		int dir = q.front().second;
		final_dir[num] = dir;
		check[num] = true;
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int nxt = num + nw[i];
			if (nxt == 0 || nxt == 5 || check[nxt])
				continue;
			if (dir == 0) // 앞의 바퀴가 회전하지 않았다면
			{
				q.push({ nxt, 0 });
				continue;
			}
			if (nxt > num)
			{
				if (wheel[num][2] == wheel[nxt][6])
					q.push({ nxt, 0 });
				else
				{
					if (dir == 1)
						q.push({ nxt, -1 });
					else
						q.push({ nxt, 1 });
				}
			}
			else
			{
				if (wheel[num][6] == wheel[nxt][2])
					q.push({ nxt, 0 });
				else
				{
					if (dir == 1)
						q.push({ nxt, -1 });
					else
						q.push({ nxt, 1 });
				}
			}
		}
	}

	// 실제 톱니바퀴를 돌림
	for (int i = 1; i <= 5; i++)
	{
		if (final_dir[i] == -1)
		{
			int tmp = wheel[i][0];
			for (int j = 0; j < 7; j++)
			{
				wheel[i][j] = wheel[i][j + 1];
			}
			wheel[i][7] = tmp;
		}
		else if (final_dir[i] == 1)
		{
			int tmp = wheel[i][7];
			for (int j = 7; j > 0; j--)
			{
				wheel[i][j] = wheel[i][j - 1];
			}
			wheel[i][0] = tmp;
		}
	}
}

int main()
{

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &wheel[i][j]);
		}
	}

	scanf("%d", &K);
	
	while (K--)
	{
		scanf("%d %d", &in_num, &in_dir);

		Spin();
	}

	int mul = 1;

	for (int i = 1; i <= 4; i++)
	{
		if (wheel[i][0] == 1)
			score += mul;
		mul *= 2;
	}

	cout << score;

	return 0;
}