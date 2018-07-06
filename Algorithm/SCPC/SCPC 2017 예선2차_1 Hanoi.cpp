#include <bits/stdc++.h>

using namespace std;

int T;
int N;
string s;

char nxt(char c, int dif)
{
	int tmp = c - 'A';
	tmp = (tmp + dif) % 3;
	char ret = tmp + 'A';
	return ret;
}

int dif(char a, char b)
{
	int ret;
	if (a == 'A')
	{
		if (b == 'B') ret = 1;
		else ret = 2;
	}
	else if (a == 'B')
	{
		if (b == 'C') ret = 1;
		else ret = 2;
	}
	else
	{
		if (b == 'A') ret = 1;
		else ret = 2;
	}
	return ret;
}

bool solve(char src, char dst, int cnt)
{
	if (cnt == 0)
		return true;

	if (dif(src, dst) == 1) // ¹Ù·Î ¿· ±âµÕÀ¸·Î °¥ ¶§
	{
		if (s[cnt] != src && s[cnt] != dst)
		{
			return false;
		}
		if (s[cnt] == src)
		{
			char here = src;
			char there = nxt(dst, 1);
			if (!solve(here, there, cnt - 1))
				return false;
		}
		else if (s[cnt] == dst)
		{
			char here = nxt(dst, 1);
			char there = dst;
			if (!solve(here, there, cnt - 1))
				return false;
		}
		else
			return false;
	}
	else // ÇÑ Ä­ ¶³¾îÁø ±âµÕÀ¸·Î °¥ ¶§
	{
		if (s[cnt] == src || s[cnt] == dst)
		{
			if (!solve(src, dst, cnt - 1))
				return false;
		}
		else
		{
			if (!solve(dst, src, cnt - 1))
				return false;
		}
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cin >> N;
		cin >> s;
		s = " " + s;

		string ans = solve('A', 'B', N) ? "YES" : "NO";

		cout << "Case #" << test << "\n";
		cout << ans << "\n";

	}

	return 0;
}