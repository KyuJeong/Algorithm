#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX 100001

using namespace std;

struct Edge
{
	int v, u, weight;
	Edge()
	{}
	Edge(int _v, int _u, int _weight)
	{
		v = _v;
		u = _u;
		weight = _weight;
	}
};

bool operator< (const Edge &edge1, const Edge &edge2)
{
	return edge1.weight < edge2.weight;
}

int V, E;
int from, to, weight;
int parent[MAX];
bool check;
int ans;
int edge_count;

vector <Edge> e;

int find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	check = false;
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	parent[u] = v;
	check = true;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		e.push_back(Edge(from, to, weight));
	}

	sort(e.begin(), e.end());

	for (int i = 0; i < E; i++)
	{
		merge(e[i].u, e[i].v);

		if (check)
		{
			edge_count++;
			ans += e[i].weight;
		}
	}

	cout << ans;

	return 0;
}