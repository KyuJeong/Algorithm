#include <iostream>

using namespace std;

int N;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	int cnt = 0;

	while (N >= 10)
	{
		int tmp = N;
		int cur = 1;
		while (tmp > 0)
		{
			cur *= (tmp % 10);
			tmp /= 10;
		}
		N = cur;
		cnt++;
	}

	cout << cnt;

	return 0;
}