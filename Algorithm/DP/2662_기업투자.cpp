#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef pair <int, int> pii;

int N, K;
int tmp;
int arr[301][21];
int DP[301][21];	// N만원까지, K기업까지 투자했을 때의 최대 이익
pii parent[301][21];

int Solve(int n, int k)
{
	int &ret = DP[n][k];

	if (n == 0 || k == 0)
		return 0;

	if (ret != -1)
		return ret;

	for (int i = 0; i <= n; i++)
	{
		int tmp = Solve(i, k - 1) + arr[n - i][k];
		if (ret < tmp)
		{
			ret = tmp;
			parent[n][k] = { i, k - 1 };
		}
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		for (int j = 1; j <= K; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ans = Solve(N, K);

	cout << ans << "\n";

	vector <int> v;

	v.push_back(N);

	int cur_idx = parent[N][K].second;
	int cur_cost = parent[N][K].first;

	pii cur = { N,K };
	
	for (int i = 1; i < K; i++)
	{
		pii nxt = { parent[cur.first][cur.second] };
		v.push_back(nxt.first);
		cur = nxt;
	}

	int pre = 0;

	for (int i = K - 1; i >= 0; i--)
	{
		cout << v[i] - pre << " ";
		pre = v[i];
	}

	return 0;
}