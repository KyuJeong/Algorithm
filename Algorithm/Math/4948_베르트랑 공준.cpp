#include <iostream>
using namespace std;

#define MAX 246912

int num[MAX + 1];
int n;
int countPrime;

int main()
{
	std::ios::sync_with_stdio(false);

	for (int i = 1; i <= MAX; i++)
	{
		num[i] = i;
	}

	for (int i = 2; i <= 500; i++)
	{
		if (num[i] != 0)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				num[j] = 0;
			}
		}
	}

	cin >> n;
	while (n != 0)
	{
		countPrime = 0;
		for (int i = n + 1; i <= n * 2; i++)
		{
			if (num[i] != 0)
				countPrime++;
		}

		cout << countPrime << "\n";
		cin >> n;
	}

	return 0;
}