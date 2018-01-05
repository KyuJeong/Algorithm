#include <iostream>

using namespace std;

int main()
{
	long long fibo[300];
	long long K;

	scanf("%lli", &K);

	fibo[1] = 1, fibo[2] = 1;
	for (int i = 3; i < 92; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int print_start = 0;

	for (int i = 91; i > 2; i--)
	{
		if (fibo[i] > K && K >= fibo[i - 1])
		{
			print_start = 1;
			printf("1");
			K -= fibo[i - 1];
		}
		else
		{
			if (print_start == 1)
				printf("0");
		}
	}

	return 0;
}
