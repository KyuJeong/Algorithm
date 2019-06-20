#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	cin >> s;

	int cnt1 = 0;
	int	cnt2 = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
			cnt1++;
		if (s[i] == 'o')
			cnt2++;
	}

	if (cnt2 == 0)
	{
		cout << "YES";
		return 0;
	}

	if (cnt1 % cnt2 == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}