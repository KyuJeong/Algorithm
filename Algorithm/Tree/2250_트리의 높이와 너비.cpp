#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

typedef pair <int, int> pii;

int N;
bool is_child[MAX];
vector <pii> T[MAX];
int u, v, w;
int l[MAX];
int r[MAX];
vector <int> d[MAX];
int width[MAX];
int root;

int dfs(int x, int depth)
{
	if (x == -1) return 0;
	d[depth].push_back(x);
	for (auto i : T[x])
	{
		l[x] += dfs(i.first, depth + 1);
		r[x] += dfs(i.second, depth + 1);
	}
	return l[x] + r[x] + 1;
}

void bfs()
{
	queue <int> q;
	q.push(root);
	width[root] = l[root] + 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : T[cur])
		{
			if (i.first != -1)
			{
				width[i.first] = width[cur] - r[i.first] - 1;
				q.push(i.first);
			}
			if (i.second != -1)
			{
				width[i.second] = width[cur] + l[i.second] + 1;
				q.push(i.second);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> u >> v >> w;
		T[u].push_back({ v,w });
		if (v != -1) is_child[v] = true;
		if (w != -1) is_child[w] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!is_child[i]) 
		{
			root = i;
			break;
		}
	}
	dfs(root, 1);
	bfs();

	int lv = 1;
	int _max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (d[i].size() == 0)
			break;
		int b = d[i].front();
		int e = d[i].back();
		if (width[e] - width[b] > _max)
		{
			lv = i;
			_max = width[e] - width[b];
		}
	}

	cout << lv << " " << _max + 1;

	return 0;
}