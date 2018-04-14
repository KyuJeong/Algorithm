#include <iostream>
#include <algorithm>

using namespace std;

int T;
int cost[4];
int day[13];
int price[13];
int _min = 1e9;

void Solve(int a, int sum)
{
	_min = min(_min, sum);

	for (int i = a + 1; i <= a + 3; i++)
	{
		int cur = sum;
		int tmp = 0;
		
		if (i >= 13)
			break;
		
		for (int j = i; j <= i + 2; j++)
		{
			if (j >= 13)
				break;
			tmp += price[j];
		}
		if (tmp > cost[2])
			Solve(i + 2, sum - tmp + cost[2]);
		else
			Solve(i + 2, sum);
	}
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		for (int i = 0; i < 4; i++)
			cin >> cost[i];

		for (int i = 1; i <= 12; i++)
			cin >> day[i];

		int sum = 0;

		for (int i = 1; i <= 12; i++)
		{
			int d = cost[0] * day[i];
			int m = cost[1];
			price[i] = min(d, m);
			sum += price[i];
		}

		_min = 1e9;

		Solve(0, sum);

		int ans = min(_min, cost[3]);

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}