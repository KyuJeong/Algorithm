#include <bits/stdc++.h>

using namespace std;

string vowel = "aioeu";

bool isVowel(char c)
{
	for (auto i : vowel)
	{
		if (i == c)
			return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;
	cin >> s;

	bool pre_vowel = true;
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i] == 'n')
			continue;
		if (!isVowel(s[i]))
		{
			if (!isVowel(s[i + 1]))
			{
				cout << "NO";
				return 0;
			}
		}
	}

	if (!isVowel(s.back()) && s.back() != 'n')
		cout << "NO";
	else
		cout << "YES";

	return 0;
}