#include <iostream>
using namespace std;

int DP0[41];
int DP1[41];

int main()
{
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int N;
	DP0[0] = 1;
	DP1[1] = 1;

	for (int i = 2; i < 41; i++)
	{
		DP0[i] = DP0[i - 1] + DP0[i - 2];
		DP1[i] = DP1[i - 1] + DP1[i - 2];
	}

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		printf("%d %d\n", DP0[N], DP1[N]);
	}

	return 0;
}