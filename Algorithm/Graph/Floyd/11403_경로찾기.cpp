#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100];
int N;
int path[100][100];
queue<int> que;

void BFS(int vtx)
{
	int cur = vtx;
	bool visit[100] = { false };

	que.push(cur);

	while (!que.empty())
	{
		if (!visit[cur])
		{
			for (int i = 0; i < G[cur].size(); i++)
			{
				que.push(G[cur][i]);
			}
		}
		que.pop();
		visit[cur] = true;
		if (!que.empty())
			cur = que.front();
		path[vtx][cur] = 1;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	int input;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			if (input == 1)
				G[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!G[i].empty())
			BFS(i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << path[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}