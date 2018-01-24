#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, W;
int D[1001];
int temp1, temp2;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N >> K;
		vector <vector <int>> v(N + 1);
		int indegree[1001] = { 0 };
		int pre_building_time[1001] = { 0 };
		queue <int> q;

		for (int i = 1; i <= N; i++)
			cin >> D[i];

		for (int i = 1; i <= K; i++)
		{
			cin >> temp1 >> temp2;
			v[temp1].push_back(temp2);
			indegree[temp2]++;
		}

		cin >> W;

		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		for (int i = 1; i <= N; i++)
		{
			if (q.empty())
			{
				return 0;
			}

			int cur = q.front();
			q.pop();

			if (cur == W)
			{
				cout << D[cur] << "\n";
				break;
			}

			for (int j = 0; j < v[cur].size(); j++)
			{
				int nxt = v[cur][j];
				pre_building_time[nxt] = max(pre_building_time[nxt], D[cur]);

				if (--indegree[nxt] == 0)
				{
					D[nxt] += pre_building_time[nxt];
					q.push(nxt);
				}
			}
		}
	}

	return 0;
}