#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

int N, K;
pii coin[1001];
int DP[3][10001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> coin[i].first >> coin[i].second;
	}

	sort(coin, coin + K);

	for (int i = 0; i <= N; i++)
	{
		DP[0][i] = 1;
	}
	DP[1][0] = 1;

	for (int i = 0; i < K; i++)
	{
		int cost = coin[i].first;
		int cnt = coin[i].second;
		for (int j = 1; j <= N; j++)
		{
			DP[2][j] = 0;
			int _min = j - (cost * cnt);
			for (int k = j; k >= 0 && k >= _min; k -= cost)
			{
				DP[2][j] += DP[1][k];
			}
		}
		for (int j = 1; j <= N; j++)
		{
			DP[1][j] = DP[2][j];
		}
	}

	cout << DP[1][N];

	return 0;
}