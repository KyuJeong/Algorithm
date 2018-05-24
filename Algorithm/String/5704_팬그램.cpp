#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (1)
	{
		getline(cin, s);
		cin.clear();
		if (s == "*")
			break;
		bool ch[26] = { false };
		for (auto i : s)
		{
			ch[i - 'a'] = true;
		}

		bool flag = true;
		for (int i = 0; i<26; i++)
		{
			if (!ch[i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}