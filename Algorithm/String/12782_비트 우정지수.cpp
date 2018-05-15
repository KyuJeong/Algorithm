#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		string s1, s2;
		int dif[2] = { 0 };

		cin >> s1 >> s2;

		int len = ;

		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == '0' && s2[i] == '1')
				dif[0]++;
			else if (s1[i] == '1' && s2[i] == '0')
				dif[1]++;
		}

		int ans = min(dif[0], dif[1]);
		ans += max(dif[0], dif[1]) - ans;

		cout << ans << "\n";

	}

	return 0;
}