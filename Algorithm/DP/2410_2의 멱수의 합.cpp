#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

int N;
int DP[1000001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		if (i % 2 == 0)
			DP[i] = DP[i - 1] + DP[i / 2];
		else
			DP[i] = DP[i - 1];
		DP[i] %= MOD;
	}

	cout << DP[N];

	return 0;
}