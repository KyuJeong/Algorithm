#include <iostream>

using namespace std;

int k;
int idx;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> k;

	int sum;
	for (int i = 1; idx != k; i++)
	{
		int cur = i;
		sum = 0;
		while (cur > 0)
		{
			sum += cur % 10;
			cur /= 10;
		}
		if (sum == 10)
			idx++;

		if (idx == k)
		{
			cout << i;
			return 0;
		}

	}

	return 0;
}