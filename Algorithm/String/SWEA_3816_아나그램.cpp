#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{
		string s, t;
		cin >> s >> t;

		int cmp[26] = { 0 };
		int cnt[26] = { 0 };
		for (auto i : s)
			cmp[i - 'a']++;


		int s_sz = s.size();
		for (int i = 0; i < s_sz - 1; i++)
			cnt[t[i] - 'a']++;

		cnt[0]++;

		int ans = 0;
		t = 'a' + t;
		int t_sz = t.size();
		for (int i = s_sz; i < t_sz; i++)
		{
			cnt[t[i - s_sz] - 'a']--;
			cnt[t[i] - 'a']++;
			bool flag = true;
			for (int i = 0; i < 26; i++)
			{
				if (cnt[i] != cmp[i])
				{
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}