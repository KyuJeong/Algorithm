#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll DP[5001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	DP[0] = 1;

	/* Ä«Å»¶õ ¼ö */
	for (int i = 1; i <= 2500; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			ll mul = (DP[j] * DP[i - 1- j]) % MOD;
			DP[i] = (DP[i] + mul) % MOD;
		}
	}

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		if (N % 2 == 1)
			cout << "0\n";
		else
			cout << DP[N / 2] << "\n";
	}

	return 0;
}