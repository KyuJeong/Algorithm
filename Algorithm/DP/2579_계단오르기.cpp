#include <iostream>
#include <algorithm>
using namespace std;

int DP[301][2];
int A[301];
int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	DP[1][0] = 0;
	DP[1][1] = A[1];
	DP[1][2] = A[1];
	DP[2][0] = A[1];
	DP[2][1] = A[2];
	DP[2][2] = A[1] + A[2];

	for (int i = 3; i <= N; i++)
	{
		DP[i][0] = max(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] = DP[i - 1][0] + A[i];
		DP[i][2] = DP[i - 1][1] + A[i];
	}

	cout << max(DP[N][1], DP[N][2]);

	return 0;
}