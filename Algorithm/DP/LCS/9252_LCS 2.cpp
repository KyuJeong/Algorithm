#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;
int DP[1001][1001];
int max_num;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> s1 >> s2;

	int size1 = s1.size();
	int size2 = s2.size();


	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			max_num = max(max_num, DP[i][j]);
		}
	}

	string ans = "";

	int i = size1;
	int j = size2;

	while (DP[i][j] != 0)
	{
		if (DP[i][j] == DP[i][j - 1])
			j--;
		else if (DP[i][j] == DP[i - 1][j])
			i--;
		else if (DP[i][j] - 1 == DP[i - 1][j - 1])
		{
			ans += s1[i - 1];
			i--;
			j--;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << max_num << "\n" << ans;

	return 0;
}