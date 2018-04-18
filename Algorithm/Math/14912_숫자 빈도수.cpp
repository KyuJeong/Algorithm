#include <iostream>

using namespace std;

int n, d;
int ans;

int Calc(int x)
{
	int ret = 0;
	while (x > 0)
	{
		int mod = x % 10;
		if (mod == d)
			ret++;
		x /= 10;
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> d;

	for (int i = 1; i <= n; i++)
	{
		int tmp = Calc(i);
		ans += tmp;
	}

	cout << ans;

	return 0;
}