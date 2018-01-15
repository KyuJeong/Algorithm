#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex, edge;
vector<int> G[1001];
bool isCount[1001];
int countComponent;

void DFS(int vtx)
{
	isCount[vtx] = true;

	for (int i = 0; i < G[vtx].size(); i++)
	{
		int nxt = G[vtx][i];
		if (!isCount[nxt])
			DFS(nxt);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int temp1, temp2;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++)
	{
		cin >> temp1 >> temp2;
		G[temp1].push_back(temp2);
		G[temp2].push_back(temp1);
	}

	for (int i = 1; i <= vertex; i++)
	{
		if (!isCount[i])
		{
			countComponent++;
			DFS(i);
		}
	}

	cout << countComponent;

	return 0;
}