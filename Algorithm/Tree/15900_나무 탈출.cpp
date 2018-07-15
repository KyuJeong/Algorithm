#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> T[500001];
bool check[500001];
int ans;

void dfs(int u, int d)
{
	check[u] = true;
	bool leaf = true;
	for (auto i : T[u])
	{
		if (check[i])
			continue;
		leaf = false;
		dfs(i, d + 1);
	}
	if (leaf)
		ans += d;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	int u, v;
	for (int i = 0; i < N; i++)
	{
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	dfs(1, 0);

	if (ans & 1)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}