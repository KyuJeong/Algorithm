#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];
int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = min(DP[i / 2], DP[i - 1]) + 1;
		if (i % 3 == 0)
			DP[i] = min(DP[i / 3], DP[i - 1]) + 1;
	}

	cout << DP[N];
	return 0;
}