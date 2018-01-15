#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, V;
int temp1, temp2;
vector<int> G[1001];
bool visit[1001];

void DFS(int x)
{
	visit[x] = true;
	cout << x << " ";

	for (int i = 0; i < G[x].size(); i++)
	{
		int nxt = G[x][i];
		if (!visit[nxt])
			DFS(nxt);
	}
}

void BFS(int a)
{
	queue<int> que;
	que.push(a);
	visit[a] = true;

	while (!que.empty())
	{
		int node = que.front();
		cout << node << " ";
		que.pop();
		for (int i = 0; i < G[node].size(); i++)
		{
			int next = G[node][i];
			if (!visit[next])
			{
				que.push(next);
				visit[next] = true;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		G[temp1].push_back(temp2);
		G[temp2].push_back(temp1);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(G[i].begin(), G[i].end());
	}

	DFS(V);
	cout << "\n";

	memset(visit, false, sizeof(visit));
	BFS(V);

	return 0;
}