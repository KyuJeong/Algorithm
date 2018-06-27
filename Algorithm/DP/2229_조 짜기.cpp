#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1001];
int DP[1002];

void solve()
{
	for (int i = N - 1; i >= 0; i--)
	{
		int _max = arr[i];
		int _min = arr[i];
		for (int j = i; j < N; j++)
		{
			if (arr[j] > _max)
				_max = arr[j];
			if (arr[j] < _min)
				_min = arr[j];
			DP[i] = max(_max - _min + DP[j + 1], DP[i]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	solve();

	cout << DP[0];

	return 0;
}