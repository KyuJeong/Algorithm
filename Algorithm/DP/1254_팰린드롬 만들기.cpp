#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> s;

	int l = 0;
	int r = s.size() - 1;
	int nxt = -1;
	int len = 0;

	while (l <= r)
	{
		if (l == r)
		{
			len++;
			break;
		}
		if (s[l] == s[r])
		{
			l++; r--;
			len += 2;
			if (s[l] == s.back() && nxt == -1)
				nxt = l;
		}
		else
		{
			len = 0;
			r = s.size() - 1;
			if (nxt != -1)
			{
				l = nxt;
				nxt = -1;
				continue;
			}	
			l++;
		}
	}

	cout << s.size() + s.size() - len;

	return 0;
}