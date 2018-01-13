#include <iostream>

using namespace std;

int t, n;

int sumOfGCD(int a, int b)
{
	int num;
	int div;
	if (a > b)
	{
		num = a;
		div = b;
	}
	else
	{
		num = b;
		div = a;
	}

	int rem = 1;

	while (rem != 0)
	{
		rem = num % div;
		num = div;
		div = rem;
	}

	return num;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> n;
		int num[100];
		long long sum = 0;

		for (int i = 0; i < n; i++)
			cin >> num[i];

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += sumOfGCD(num[i], num[j]);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}