#include <iostream>

using namespace std;

int N;
int DP[18];
bool upper[1001];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	DP[1] = 1;
	upper[1] = true;

	for (int i = 2; i <= 17; i++)
	{
		DP[i] = DP[i - 2] + DP[i - 1];
		upper[DP[i]] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (upper[i])
			cout << "O";
		else
			cout << "o";
	}


	return 0;
}