#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int cnt[26];
int max_val;
int max_idx;
char ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> s;

	for (auto i : s)
	{
		if (i < 'a')
			cnt[i - 'A']++;
		else
			cnt[i - 'a']++;
	}

	max_val = -1;

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > max_val)
		{
			max_val = cnt[i];
			max_idx = i;
			ans = i + 'A';
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == max_val && max_idx != i)
			ans = '?';
	}

	cout << ans;

	return 0;
}