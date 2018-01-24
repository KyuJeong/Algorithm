#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int v, u, weight;
	Edge()
	{ }
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

int N, M;
char gender[1001];
int from, to, weight;
int parent[1001];
bool check;
int ans;
int count_link;
vector <Edge> v;

int find(int x)
{
	if (x == parent[x])
		return x;

	return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	parent[u] = v;
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= N; i++)
		cin >> gender[i];

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> weight;
		if (gender[from] != gender[to])
		{
			v.push_back(Edge(from, to, weight));
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (merge(v[i].u, v[i].v))
		{
			ans += v[i].weight;
			count_link++;
		}
	}

	if (count_link != N - 1)
		cout << "-1";
	else
		cout << ans;

	return 0;
}