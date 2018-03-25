#include <iostream>

using namespace std;

int N;

int Solve(int a)
{
	
	int pre = a % 10;
	a /= 10;
	int cur = a % 10;
	int dif = pre - cur;
	pre = cur;

	while (a >= 10)
	{
		a /= 10;
		int cur = a % 10;
		if (pre - cur != dif)
			return 0;

		pre = cur;
	}
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	if (N < 100)
	{
		cout << N;
		return 0;
	}

	int ans = 99;

	for (int i = 100; i <= N; i++)
	{
		ans += Solve(i);
	}

	cout << ans;

	return 0;
}