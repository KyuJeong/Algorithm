#include <iostream>
#include <algorithm>
using namespace std;

int upDP[1000];
int downDP[1000][1000];
int finalDownDP[1000];
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
		upDP[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j] && upDP[i] < upDP[j] + 1)
				upDP[i] = upDP[j] + 1;
		}

	}

	for (int k = 0; k < N; k++)
	{
		finalDownDP[k] = 1;
		for (int i = k; i < N; i++)
		{
			downDP[k][i] = 1;
			for (int j = k; j < i; j++)
			{
				if (A[i] < A[j] && downDP[k][i] < downDP[k][j] + 1)
					downDP[k][i] = downDP[k][j] + 1;
			}
		}
		finalDownDP[k] = *max_element(downDP[k], downDP[k] + N);
	}

	for (int i = 0; i < N; i++)
	{
		if (maxLength < upDP[i] + finalDownDP[i] - 1)
			maxLength = upDP[i] + finalDownDP[i] - 1;
	}

	cout << maxLength;

	return 0;
}