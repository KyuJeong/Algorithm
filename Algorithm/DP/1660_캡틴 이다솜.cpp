#include <iostream>
#include <algorithm>

using namespace std;

int canon[123];
int A[123];
int DP[300001];
int N;
int cnt;

int main()
{
	std::ios::sync_with_stdio(false);
	
	for (int i = 1; i < 123; i++)
	{
		canon[i] = canon[i - 1] + i;
		A[i] = A[i - 1] + canon[i];
	}

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		DP[i] = i;
		for (int j = 1; A[j] <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - A[j]] + 1);
		}
	}

	cout << DP[N];

	return 0;
}