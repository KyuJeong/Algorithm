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
		for (int j = 1; j * j <= i; j++)
		{
			if (i % j == 0)
				ans++;
		}
	}

	cout << ans;

	return 0;
}