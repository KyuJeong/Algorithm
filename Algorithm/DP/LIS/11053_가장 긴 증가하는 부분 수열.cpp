#include <iostream>
using namespace std;

int DP[1000];
int A[1000];
int N;
int maxLength = 1;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}


	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j] && DP[i] < DP[j] + 1)
				DP[i] = DP[j] + 1;
		}

		if (maxLength < DP[i])
			maxLength = DP[i];
	}

	cout << maxLength;

	return 0;
}