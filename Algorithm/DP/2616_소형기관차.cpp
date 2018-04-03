#include <iostream>
#include <algorithm>

using namespace std;

int N;
int tmp;
int train;
int DP[50001][3];
int s[50001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		s[i] = s[i - 1] + tmp;
	}

	cin >> train;

	for (int i = train; i <= N; i++)
	{
		DP[i][0] = max(DP[i - 1][0], s[i] - s[i - train]);
		DP[i][1] = max(DP[i - 1][1], DP[i - train][0] + s[i] - s[i - train]);
		DP[i][2] = max(DP[i - 1][2], DP[i - train][1] + s[i] - s[i - train]);
	}

	cout << DP[N][2];

	return 0;
}