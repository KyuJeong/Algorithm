#include <iostream>
#include <vector>
using namespace std;

vector <int> G[101];
int vertex, edge;
int u, v;
bool check[101];
int virusCom;

void DFS(int cur)
{
	check[cur] = true;
	for (int i = 0; i < G[cur].size(); i++)
	{
		int nxt = G[cur][i];
		if (!check[nxt])
			DFS(nxt);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(1);

	for (int i = 2; i <= vertex; i++)
	{
		if (check[i])
			virusCom++;
	}

	cout << virusCom;

	return 0;
}