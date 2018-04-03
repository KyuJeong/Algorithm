#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string tmp, s1, s2, s3;
int DP[101][101][101];
int ans = 0;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> tmp;
	s1 = '0' + tmp;
	cin >> tmp;
	s2 = '0' + tmp;
	cin >> tmp;
	s3 = '0' + tmp;

	for (int i = 1; i < s1.size(); i++)
	{
		for (int j = 1; j < s2.size(); j++)
		{
			for (int k = 1; k < s3.size(); k++)
			{
				if (s1[i] == s2[j] && s2[j] == s3[k])
					DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
				else
					DP[i][j][k] = max({ DP[i - 1][j][k],DP[i][j - 1][k],DP[i][j][k - 1] });
				ans = max(ans, DP[i][j][k]);
			}
		}
	}

	cout << ans;

	return 0;
}