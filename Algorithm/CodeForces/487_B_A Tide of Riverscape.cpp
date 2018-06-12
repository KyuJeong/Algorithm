#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, p;
	string s;

	cin >> n >> p;
	cin >> s;

	bool ans = false;

	for (int i = 0; i < s.size() - p; i++)
	{
		if (s[i] == '1')
		{
			if (s[i + p] == '0')
			{
				ans = true;
				break;
			}
			else if (s[i + p] == '.')
			{
				s[i + p] = '0';
				ans = true;
				break;
			}
		}
		else if (s[i] == '0')
		{
			if (s[i + p] == '1')
			{
				ans = true;
				break;
			}
			else if (s[i + p] == '.')
			{
				s[i + p] = '1';
				ans = true;
				break;
			}
		}
		else
		{
			if (s[i + p] == '0')
			{
				s[i] = '1';
				ans = true;
				break;
			}
			else if (s[i + p] == '1')
			{
				s[i] = '0';
				ans = true;
				break;
			}
			else
			{
				s[i] = '0';
				s[i + p] = '1';
				ans = true;
				break;
			}
		}
	}

	if (!ans)
		cout << "No";
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
			{
				s[i] = '0';
			}
		}
		cout << s;
	}


	return 0;
}