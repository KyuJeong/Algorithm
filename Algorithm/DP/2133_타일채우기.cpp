#include <iostream>
using namespace std;

int DP[31];
int N;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[0] = 1;
	DP[2] = 3;

	if (N % 2 == 1)
	{
		cout << "0";
	}
	else
	{
		for (int i = 4; i <= N; i += 2)
		{
			DP[i] = DP[i - 2] * 3;
			for (int j = 0; j < i - 2; j += 2)
			{
				DP[i] += DP[j] * 2;
			}
		}

		cout << DP[N];
	}

	return 0;
}