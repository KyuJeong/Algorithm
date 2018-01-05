#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501];
int line;
int tmp;
int DP[501];
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		cin >> arr[tmp];
		line = max(line, tmp);
		line = max(line, arr[tmp]);
	}

	for (int i = 1; i <= line; i++)
	{
		if (arr[i] == 0)
			continue;
		DP[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && DP[j] + 1 > DP[i])
				DP[i] = DP[j] + 1;
		}
		ans = max(ans, DP[i]);
	}

	cout << N - ans;

	return 0;
}