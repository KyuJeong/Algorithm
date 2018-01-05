#include <iostream>
using namespace std;

int cur[100000];
int nxt[100000];

int main()
{
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;
	cur[0] = N;
	int cnt = 1;
	int cur_cnt = 0;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (cur[j] % 3 == 0)
			{
				nxt[cur_cnt] = cur[j] / 3;
				if (nxt[cur_cnt] == 1)
				{
					ans = i;
					break;
				}
				cur_cnt++;

			}

			else
			{
				if (cur[j] % 2 == 0)
				{
					nxt[cur_cnt] = cur[j] / 2;
					if (nxt[cur_cnt] == 1)
					{
						ans = i;
						break;
					}
					cur_cnt++;

				}
				nxt[cur_cnt] = cur[j] - 1;
				if (nxt[cur_cnt] == 1)
				{
					ans = i;
					break;
				}
				cur_cnt++;
			}
		}

		if (ans != 0)
			break;
		for (int j = 0; j < cur_cnt; j++)
		{
			cur[j] = nxt[j];
		}

		cnt = cur_cnt;
		cur_cnt = 0;
	}

	cout << ans + 1;

	return 0;
}