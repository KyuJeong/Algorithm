#include <iostream>
#include <vector>

using namespace std;

int N, M;
int num;
int pre, cur;
int indegree[1001];
int check[1001];
vector <int> ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vector <vector <int>> v(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		cin >> pre;
		for (int j = 0; j < num - 1; j++)
		{
			cin >> cur;
			v[pre].push_back(cur);
			indegree[cur]++;
			pre = cur;
		}
	}

	while (ans.size() != N)
	{
		bool cycle_flag = true;

		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0 && !check[i])
			{
				ans.push_back(i);
				check[i] = true;
				for (int j = 0; j < v[i].size(); j++)
				{
					int point = v[i][j];
					indegree[point]--;
				}
				cycle_flag = false;
				break;
			}
		}
		if (cycle_flag)
		{
			cout << "0";
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}