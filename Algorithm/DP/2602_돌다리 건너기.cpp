#include <iostream>
#include <string>

using namespace std;

string cmp;
string str1, str2;
int DP[101][101];
int DP2[101][101];

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> cmp >> str1 >> str2;

	int cmp_len = cmp.size();
	int str_len = str1.size();

	for (int i = 0; i < str_len; i++)
	{
		if(i != 0)
			DP[i][0] = DP[i - 1][0];
		if (str1[i] == cmp[0])
		{
			DP[i][0]++;
		}
	}

	for (int i = 1; i < str_len; i++)
	{
		for (int j = 1; j < cmp_len; j++)
		{
			DP[i][j] = DP[i - 1][j];
			if (j % 2 == 0)
			{
				if (cmp[j] == str1[i])
					DP[i][j] += DP[i - 1][j - 1];
			}
			else
			{
				if (cmp[j] == str2[i])
					DP[i][j] += DP[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < str_len; i++)
	{
		if (i != 0)
			DP2[i][0] = DP2[i - 1][0];
		if (str2[i] == cmp[0])
		{
			DP2[i][0]++;
		}
	}

	for (int i = 1; i < str_len; i++)
	{
		for (int j = 1; j < cmp_len; j++)
		{
			DP2[i][j] = DP2[i - 1][j];
			if (j % 2 == 0)
			{
				if (cmp[j] == str2[i])
					DP2[i][j] += DP2[i - 1][j - 1];
			}
			else
			{
				if (cmp[j] == str1[i])
					DP2[i][j] += DP2[i - 1][j - 1];
			}
		}
	}

	int ans = DP[str_len - 1][cmp_len - 1] + DP2[str_len - 1][cmp_len - 1];

	cout << ans;

	return 0;
}