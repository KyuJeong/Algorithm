#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long A[51];
long long B[51];
long long ans = -LLONG_MAX;
long long max_val = -LLONG_MAX;
long long max_idx;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			long long tmp = A[i] * B[j];
			if (max_val < tmp)
			{
				max_val = tmp;
				max_idx = i;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == max_idx)
				continue;
			long long tmp = A[i] * B[j];
			if (ans < tmp)
				ans = tmp;
		}
	}

	cout << ans;

	return 0;
}