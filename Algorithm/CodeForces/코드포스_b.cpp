#include <iostream>
#include <cmath>

using namespace std;

long long n, k;

long long arr[63];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n >> k;

	arr[1] = 1;
	for (int i = 2; i <= 62; i++)
	{
		arr[i] = arr[i - 1] * 2;
	}

	if (k == 1)
		cout << n;
	else
	{
		for (int i = 1; i <= 62; i++)
		{
			if (n < arr[i])
			{
				cout << arr[i] - 1;
				break;
			}
		}
	}

	return 0;
}