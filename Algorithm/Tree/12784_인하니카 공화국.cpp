#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

int T;
int N, M;
vector <vector <pii>> v;
bool check[1001];

int Traversal(int cur, int cost)
{
	int sum = 0;

	check[cur] = true;

	for (pii i : v[cur])
	{
		if(!check[i.first])
			sum += Traversal(i.first, i.second);
	}

	if (sum == 0)
		return cost;

	int ret = min(sum, cost);

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		if (N == 1)
		{
			cout << "0\n";
			continue;
		}

		v.resize(N + 1);

		int a, b, c;

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}

		int ans = Traversal(1, 1e9);

		cout << ans << "\n";

		v.clear();
		memset(check, false, sizeof(check));

	}

	return 0;
}