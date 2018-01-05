#include <iostream>

using namespace std;

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
	}

	DP[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = arr[i]; j <= M; j++)
		{
			DP[j] += DP[j - arr[i]];
		}
	}

	cout << DP[M];

	return 0;
}