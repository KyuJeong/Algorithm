#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100000

struct Planet
{
	int x;
	int y;
	int z;
	int idx;
};

struct Edge
{
	Edge()
	{}
	Edge(int _p, int _q, int _weight)
	{
		p = _p;
		q = _q;
		weight = _weight;
	}

	int p;
	int q;
	int weight;
};

int N;
bool check[MAX];
int weight_sum;
int parent[MAX];

bool cmpX(const Planet &p1, const Planet &p2)
{
	return p1.x < p2.x;
}

bool cmpY(const Planet &p1, const Planet &p2)
{
	return p1.y < p2.y;
}

bool cmpZ(const Planet &p1, const Planet &p2)
{
	return p1.z < p2.z;
}

bool operator< (const Edge &edge1, const Edge &edge2)
{
	return edge1.weight > edge2.weight;
}

int find(int u)
{
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

bool merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	parent[v] = parent[u];
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	vector<Planet> planet(N);
	priority_queue <Edge> que;

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		planet[i].idx = i;
	}

	sort(planet.begin(), planet.end(), cmpX);
	for (int i = 1; i < N; i++)
	{
		Edge edge(planet[i - 1].idx, planet[i].idx, abs(planet[i - 1].x - planet[i].x));
		que.push(edge);
	}

	sort(planet.begin(), planet.end(), cmpY);
	for (int i = 1; i < N; i++)
	{
		Edge edge(planet[i - 1].idx, planet[i].idx, abs(planet[i - 1].y - planet[i].y));
		que.push(edge);
	}

	sort(planet.begin(), planet.end(), cmpZ);
	for (int i = 1; i < N; i++)
	{
		Edge edge(planet[i - 1].idx, planet[i].idx, abs(planet[i - 1].z - planet[i].z));
		que.push(edge);
	}

	while (!que.empty())
	{
		int idx1 = que.top().p;
		int idx2 = que.top().q;

		if (merge(idx1, idx2))
			weight_sum += que.top().weight;

		que.pop();
	}

	cout << weight_sum;

	return 0;
}