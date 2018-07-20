#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int len = s.size() - 1;
	bool palin = true;
	char c = s[0];
	bool same = true;
	for (int i = 0; i <= len / 2; i++)
	{
		if (s[i] != c || s[len - i] != c)
			same = false;
		if (s[i] == s[len - i])
			continue;
		else
			palin = false;
	}

	if (same)
		cout << "-1";
	else
	{
		if (palin)
			cout << len;
		else
			cout << len + 1;
	}

	return 0;
}