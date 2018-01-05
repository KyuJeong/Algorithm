#include <iostream>
using namespace std;

int DP[41];
int seat, fix;
int cur, pre, gap;
int count_case;

int main()
{
	std::ios::sync_with_stdio(false);

	count_case = 1;
	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cin >> seat >> fix;

	for (int i = 0; i < fix; i++)
	{
		cin >> cur;
		gap = cur - pre - 1;
		count_case *= DP[gap];
		pre = cur;
	}

	gap = seat - pre;
	count_case *= DP[gap];

	cout << count_case;

	return 0;
}