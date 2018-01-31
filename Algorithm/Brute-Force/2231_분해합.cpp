#include <iostream>

using namespace std;

int N;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int cur = i;
		int ctor = cur;
		while (cur > 0)
		{
			ctor += cur % 10;
			cur /= 10;
		}
		if (ctor == N)
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}