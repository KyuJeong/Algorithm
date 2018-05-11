#include <bits/stdc++.h>

using namespace std;

string s1, s2;
long long num1, num2;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s1 >> s2;

	int len1 = s1.size();
	int len2 = s2.size();

	for (int i = 0; i < len1; i++)
	{
		int idx = len1 - 1 - i;
		if (s1[i] == '1')
			num1 |= (1 << idx);
	}

	for (int i = 0; i < len2; i++)
	{
		int idx = len2 - 1 - i;
		if (s2[i] == '1')
			num2 |= (1 << idx);
	}

	long long mul = num1 * num2;

	vector <long long> ans;

	while (mul > 0)
	{
		ans.push_back(mul & 1);
		mul >>= 1;
	}

	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}

	return 0;
}