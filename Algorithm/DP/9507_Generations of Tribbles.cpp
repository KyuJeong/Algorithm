#include <iostream>
using namespace std;

int main()
{
	int t, n;

	scanf("%d", &t);

	long long DP[69];

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i < 68; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];
	}

	while(t--)
	{		
		scanf("%d", &n);
		printf("%d", DP[n]);
	}

	return 0;
}