#include <iostream>
#include <string>

using namespace std;

string str;
int len;
bool P[2501][2501];
int DP[2501];

void CheckPalindrome()
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= len - i; j++)
		{
			if (i == 0)
				P[j + 1][j + 1] = true;
			else if (i == 1)
			{
				if (str[j] == str[j + 1])
					P[j + 1][j + 2] = true;
			}
			else
			{
				if (str[j] == str[j + i] && P[j + 2][j + i] == 1)
					P[j + 1][j + i + 1] = true;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> str;

	len = str.size();
	CheckPalindrome();


	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (P[j][i] == true)
			{
				if (DP[i] == 0 || DP[j - 1] + 1 < DP[i])
					DP[i] = DP[j - 1] + 1;
			}
		}
	}

	cout << DP[len];

	return 0;
}