#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int N, M, T, f, t;
int H[101];
vi v[101];
int DP[101][501];

int DFS(int A, int K)
{
	int &ret = DP[A][K];
	
	if (ret != -1)
		return ret;

	if (K == 0)
		return H[A];

	ret = 1e9;
	for (auto i : v[A])
	{
		ret = min(ret, DFS(i, K - 1));
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int A, K;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> H[i];
	}

	while (M--)
	{
		cin >> f >> t;
		v[f].push_back(t);
		v[t].push_back(f);
	}

	cin >> T;

	memset(DP, -1, sizeof(DP));

	while (T--)
	{
		cin >> A >> K;

		if (v[A].size() == 0)
		{
			cout << "-1\n";
			continue;
		}

		DFS(A, K);

		cout << DP[A][K] << "\n";
	}

	return 0;
}