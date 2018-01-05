#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int cur[500] = { 0 };
	int next[500] = { 0 };
	int num;

	scanf("%d", &cur[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &num);
			if (j == 0)
				next[j] = cur[j] + num;
			else if (j == i)
				next[j] = cur[j - 1] + num;
			else
			{
				if (cur[j - 1] > cur[j])
					next[j] = cur[j - 1] + num;
				else
					next[j] = cur[j] + num;
			}
		}
		for (int j = 0; j <= i; j++)
			cur[j] = next[j];
	}

	printf("%d", *max_element(cur, cur + n));

	return 0;
}