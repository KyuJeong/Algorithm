#include <iostream>
#include <algorithm>

using namespace std;

int T;

int Solve(int x)
{
	int cur = x;
	int ret = cur;

	while (cur != 1)
	{
		if (cur % 2 == 0)
			cur /= 2;
		else
			cur = cur * 3 + 1;
		ret = max(ret, cur);
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		int ans = Solve(n);
		cout << ans << "\n";
	}

	return 0;
}