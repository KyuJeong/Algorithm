#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000

int DP[5000][3];
int pSize;
string password;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> password;
	pSize = password.size();

	DP[1][1] = 1;
	DP[2][1] = 1;

	if (password[1] == 48)
		DP[2][1] = 0;

	if (password[0] <= 49 || (password[0] == 50 && password[1] <= 54))
	{
		DP[2][2] = 1;
	}

	for (int i = 3; i <= pSize; i++)
	{
		if (password[i - 1] != 48)
			DP[i][1] = DP[i - 1][1] % MOD + DP[i - 1][2] % MOD;

		if (password[i - 2] == 49 || (password[i - 2] == 50 && password[i - 1] <= 54))
		{
			DP[i][2] = DP[i - 2][1] % MOD + DP[i - 2][2] % MOD;
		}
	}

	if (password[0] == 48)
		cout << 0;
	else
		cout << (DP[pSize][1] + DP[pSize][2]) % MOD;

	return 0;
}