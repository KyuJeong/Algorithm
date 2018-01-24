#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int pre, cur;
int indegree[32001];
bool check[32001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	vector <vector <int>> v(N + 1);
	queue <int> que;
	vector <int> ans;

	for (int i = 0; i < M; i++)
	{
		cin >> pre >> cur;
		v[pre].push_back(cur);
		indegree[cur]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	for (int i = 1; i <= N; i++)
	{
		int out = que.front();
		ans.push_back(out);
		que.pop();
		for (int i = 0; i < v[out].size(); i++)
		{
			int point = v[out][i];
			indegree[point]--;
			if (indegree[point] == 0)
				que.push(point);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}