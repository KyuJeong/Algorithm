#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int G[1001][1001];
string ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> str1 >> str2;
	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				G[i][j] = G[i - 1][j - 1] + 1;
			else
				G[i][j] = max(G[i][j - 1], G[i - 1][j]);
		}
	}

	cout << G[len1][len2];

	return 0;
}