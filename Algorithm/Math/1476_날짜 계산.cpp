#include <iostream>
using namespace std;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int a = 1;

	if (E % 15 == 0)
		E = 0;

	if (S % 28 == 0)
		S = 0;

	if (M % 19 == 0)
		M = 0;

	while (1)
	{
		if (a % 15 == E  && a % 28 == S && a % 19 == M)
		{
			printf("%d\n", a);
			break;
		}
		a++;
	}

	return 0;
}