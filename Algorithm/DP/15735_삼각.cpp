#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll DP[10001];
ll RP[10001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;

	cin >> N;

	int a = 3;
	ll add = 1;
	DP[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		RP[i] += add + RP[i - 2];
		add += i;
		DP[i] = DP[i - 1] + add;
	}

	cout << DP[N] + RP[N];

	return 0;
}