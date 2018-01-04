#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 999999999

int N;
int cost[11][11];
int ans = INF;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> cost[i][j];
		}
	}

	do
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			int cur = arr[i];
			int nxt = arr[i + 1];
			if (cost[cur][nxt] == 0)
			{
				sum = INF;
				break;
			}
			sum += cost[cur][nxt];
		}
		sum += cost[arr[N - 1]][arr[0]];	// 처음 도시로 돌아오는 비용
		ans = min(ans, sum);
	} while (next_permutation(arr.begin() + 1, arr.end()));	// 도시 방문 순서

	cout << ans;

	return 0;
}