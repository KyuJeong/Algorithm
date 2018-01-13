#include <iostream>

using namespace std;

bool D[10001];

int main()
{
	std::ios::sync_with_stdio(false);

	for (int i = 1; i <= 10000; i++)
	{
		int tmp = i;
		int res = i;
		while (tmp > 0)
		{
			res += tmp % 10;
			tmp /= 10;
		}
		if (res <= 10000)
			D[res] = true;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (!D[i])
			cout << i << "\n";
	}

	return 0;
}