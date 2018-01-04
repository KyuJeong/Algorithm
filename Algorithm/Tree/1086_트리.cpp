#include <iostream>
#include <vector>
using namespace std;
#define MAX 50

int N;
int u;
int root;
int delete_node;
int leaf_count;
vector <int> node[MAX];

void DFS(int parent, int cur)
{
	if (cur == delete_node)
	{
		if (node[parent].size() == 1)
			leaf_count++;
		return;
	}

	if (node[cur].size() == 0)
	{
		leaf_count++;
		return;
	}

	for (int i = 0; i < node[cur].size(); i++)
	{
		DFS(cur, node[cur][i]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> u;
		if (u == -1)
			root = i;
		else
			node[u].push_back(i);
	}

	cin >> delete_node;
	if (delete_node == root)
	{
		cout << "0";
		return 0;
	}
	else
		DFS(-1, root);

	cout << leaf_count;

	return 0;
}