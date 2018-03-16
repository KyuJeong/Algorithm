#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string tmp1, tmp2;
string str1, str2;

int DP[4001][4001];
int _max;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> tmp1 >> tmp2;

	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i < len1; i++)
	{
		for (int j = 1; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
				_max = max(_max, DP[i][j]);
			}
		}
	}

	cout << _max;

	return 0;
}