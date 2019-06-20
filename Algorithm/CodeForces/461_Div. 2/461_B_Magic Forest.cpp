#include <iostream>

using namespace std;

int n;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int tmp = i ^ j;
			if (tmp >= i + j || tmp > n || tmp <= i || tmp <= j)
				continue;
			ans++;
		}
	}

	cout << ans;

	return 0;
}