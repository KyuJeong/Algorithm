#include <iostream>
using namespace std;

#define MAX 1000000

int num[MAX + 1];
int n;

int main()
{
	for (int i = 1; i <= MAX; i++)
	{
		num[i] = i;
	}

	for (int i = 2; i * i <= MAX; i++)
	{
		if (num[i] != 0)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				num[j] = 0;
			}
		}
	}

	scanf("%d", &n);
	while (n)
	{
		for (int i = 3; i <= n / 2; i += 2)
		{
			if (num[i] != 0 && num[n - i] != 0)
			{
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}

		scanf("%d", &n);
	}

	return 0;
}