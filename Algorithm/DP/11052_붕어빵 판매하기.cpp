#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001];
int N;
int P[1001];

int main()
{

	std::ios::sync_with_stdio(false);

	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	DP[1] = P[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			DP[i] = max(DP[i], DP[i - j] + P[j]);
		}
	}

	cout << DP[N];

	return 0;
}