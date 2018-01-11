#include <iostream>
#include <algorithm>

using namespace std;

#define NOP -888888

int N, M;

int arr[101];
int DP[101][51];
int s[101];
bool check[101][51];

int solve(int a, int b)
{
	if (b == 0)	// DP[N][1] 채울 때 사용
		return 0;

	if (a <= 0)
		return -999999999;

	if (check[a][b])
		return DP[a][b];

	check[a][b] = true;

	DP[a][b] = solve(a - 1, b);

	for (int k = 1; k <= a; k++)
	{
		int tmp = solve(k - 2, b - 1);
		DP[a][b] = max(DP[a][b], tmp + s[a] - s[k - 1]);
	}

	return DP[a][b];
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		s[i] = s[i - 1] + arr[i];
	}

	cout << solve(N, M);

	return 0;
}