#include <iostream>
using namespace std;

long long int DP[91];
int N;

int main()
{

	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N];

	return 0;
}