#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair <int, int> pii;

int T;
int N;
pii H, R;
vector <pii> C;
vector <int> v[103];
bool visit[103];
bool ans;

void DFS(int x)
{
	if (ans)
		return;
	int cur = x;
	visit[cur] = true;

	if (cur == N - 1)
	{
		ans = true;
		return;
	}

	for (auto i : v[cur])
	{
		if (visit[i])
			continue;
		DFS(i);
		if (ans)
			return;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N;
		N += 2;
		C.resize(N);
		for (int i = 0; i < N; i++)
			cin >> C[i].first >> C[i].second;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int dist = abs(C[i].first - C[j].first) + abs(C[i].second - C[j].second);
				if (i == j)
					continue;
				if (dist <= 1000)
					v[i].push_back(j);
			}
		}

		DFS(0);

		if (ans)
			cout << "happy\n";
		else
			cout << "sad\n";

		for (int i = 0; i < N; i++)
		{
			v[i].clear();
		}
		C.clear();
		memset(visit, false, sizeof(visit));
		ans = false;
	}

	return 0;
}