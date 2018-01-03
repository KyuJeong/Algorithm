#include <iostream>

using namespace std;

int T, N, M;

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &M);
		int ans = 1;

		for (int i = 0; i < N; i++)
			ans = ans * (M - i) / (i + 1);

		printf("%d\n", ans);
	}

	return 0;
}