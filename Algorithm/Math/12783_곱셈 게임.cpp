#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int T;
int DP[1000001];
bool card[10];

int Solve(int x)
{
	int &ret = DP[x];
	if (ret != -1)
		return ret;

	bool oneshot = true;
	int num = x;
	while (num > 0)
	{
		if (!card[num % 10])
		{
			oneshot = false;
			break;
		}
		num /= 10;
	}

	if (oneshot)
	{
		ret = 0;
		return ret;
	}
	int _min = 1e9;

	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			int n1 = Solve(i);
			int n2 = Solve(x / i);
			if (n1 == -2 || n2 == -2)
				continue;

			_min = min(_min, n1 + n2 + 1);
		}
	}
	if (_min == 1e9)
		ret = -2;
	else
		ret = _min;

	return DP[x];
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		memset(DP, -1, sizeof(DP));
		memset(card, false, sizeof(card));
		int N;
		cin >> N;
		int tmp;
		
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			card[tmp] = true;
		}

		int M, K;
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> K;
			int ans = Solve(K);
			if (ans == -2)
				ans = -1;
			cout << ans << "\n";
		}

	}

	return 0;
}