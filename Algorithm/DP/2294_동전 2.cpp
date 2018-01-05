#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2147483646

int N, M;
int arr[101];
int DP[10001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (arr[i] > 10000)
			arr[i] = 0;
	}

	for (int i = 1; i <= M; i++)
		DP[i] = INF;

	DP[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		DP[arr[i]] = 1;
		for (int j = arr[i]; j <= M; j++)
		{
			DP[j] = min(DP[j], DP[j - arr[i]] + 1);
		}
	}

	if (DP[M] == INF)
		cout << "-1";
	else
		cout << DP[M];

	return 0;
}