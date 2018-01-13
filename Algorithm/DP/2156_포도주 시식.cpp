#include <iostream>
#include <algorithm>
using namespace std;

int DP[10000][3];
int A[10000];
int n;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < 3; i++)
	{
		DP[0][i] = A[0];
	}
	DP[1][0] = A[0];
	DP[1][1] = A[1];
	DP[1][2] = A[0] + A[1];

	for (int i = 2; i < n; i++)
	{
		DP[i][0] = *max_element(DP[i - 1], DP[i - 1] + 3);
		DP[i][1] = DP[i - 1][0] + A[i];
		DP[i][2] = DP[i - 1][1] + A[i];
	}

	cout << *max_element(DP[n - 1], DP[n - 1] + 3);


	return 0;
}