#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;

int T, N;
int G[11][11];
vector <pii> v;
vector <pii> stair_G(3);
int dist[11][3];
int stair_len[3];
int cnt;
int _min;

void Solve();
void Move(bool perm[11][3]);

void Solve()
{
	for (int i = 0; i <= cnt; i++)
	{
		vector <int> arr;
		for (int j = 0; j < i; j++)
		{
			arr.push_back(1);
		}

		for (int j = i; j < cnt; j++)
		{
			arr.push_back(2);
		}

		do
		{
			bool perm[11][3] = { false };

			for (int j = 0; j < cnt; j++)
			{
				if (arr[j] == 1)
					perm[j][1] = true;
				else
					perm[j][2] = true;
			}

			Move(perm);

		} while (next_permutation(arr.begin(), arr.end()));

	}
}

void Move(bool perm[11][3])
{
	queue <int> que_1;
	queue <int> que_2;
	queue <pii> stair_1;
	queue <pii> stair_2;
	int time = 1;
	int complete_cnt = 0;

	while (complete_cnt < cnt)
	{
		time++;
		for (int i = 0; i < cnt; i++)
		{
			if (perm[i][1] && dist[i][1] == time)
				que_1.push(i);

			else if (perm[i][2] && dist[i][2] == time)
				que_2.push(i);
		}

		if (stair_1.size() > 0)
		{
			while (stair_1.front().second <= time)
			{
				complete_cnt++;
				stair_1.pop();
				if (stair_1.size() == 0)
					break;
			}
		}

		if (stair_2.size() > 0)
		{
			while (stair_2.front().second <= time)
			{
				complete_cnt++;
				stair_2.pop();
				if (stair_2.size() == 0)
					break;
			}
		}

		while (stair_1.size() < 3)
		{
			if (que_1.size() == 0)
				break;
			int cur = que_1.front();
			que_1.pop();
			stair_1.push({ cur,time + stair_len[1] });
		}

		while (stair_2.size() < 3)
		{
			if (que_2.size() == 0)
				break;
			int cur = que_2.front();
			que_2.pop();
			stair_2.push({ cur,time + stair_len[2] });
		}

	}
	_min = min(_min, time);
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N;
		int idx = 1;

		_min = 1e9;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> G[i][j];

				if (G[i][j] == 0)
					continue;
				if (G[i][j] == 1)
					v.push_back({ i, j });
				else
				{
					stair_len[idx] = G[i][j];
					stair_G[idx++] = { i,j };
				}
			}
		}

		cnt = v.size();

		for (int i = 0; i < cnt; i++)
		{
			for (int j = 1; j <= 2; j++)
			{
				int cy = v[i].first;
				int cx = v[i].second;
				int sy = stair_G[j].first;
				int sx = stair_G[j].second;
				dist[i][j] = abs(cy - sy) + abs(cx - sx) + 1;
			}
		}

		Solve();

		v.clear();
		memset(G, 0, sizeof(G));

		cout << "#" << test << " " << _min << "\n";
	}

	return 0;
}