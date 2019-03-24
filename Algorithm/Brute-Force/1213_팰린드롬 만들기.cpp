#include <bits/stdc++.h>

using namespace std;

int odd_cnt;
int odd_idx;
int cnt[26];
string s;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;
	int len = s.size();

	for (auto i : s)
		cnt[i - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] & 1)
		{
			odd_cnt++;
			odd_idx = i;
		}
	}
	cnt[odd_idx]--;

	if (odd_cnt >= 2)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < cnt[i]; j += 2)
				cout << (char)(i + 'A');
		}
		if (odd_cnt & 1) cout << (char)(odd_idx + 'A');
		for (int i = 25; i >= 0; i--)
		{
			for (int j = 0; j < cnt[i]; j += 2)
				cout << (char)(i + 'A');
		}
	}

	return 0;
}