#include <bits/stdc++.h>

using namespace std;

int num[100005];
bool t[100005];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	cin >> s;

	int idx = 0;
	int cnt = 0;
	bool tw = false;

	for (int i = 0; i < s.size(); i++)
	{
		if (tw)
		{
			if (s[i] == '2')
			{
				tw = true;
				idx++;
			}
			if (s[i] == '0')
				cnt++;
		}
		else
		{
			if (s[i] == '2')
			{
				num[idx++] = cnt;
				cnt = 0;
			}
			else if (s[i] == '0')
				cnt++;
		}
	}

	num[idx] = cnt;

	string tmp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '0')
			tmp += s[i];
	}

	sort(tmp.begin(), tmp.end());
	string ans = "";
	idx = 0;
	for (int j = 0; j < num[idx]; j++)
		ans += '0';
	for (int i = 0; i < tmp.size(); i++)
	{
		
		if (tmp[i] == '2')
		{
			ans += '2';
			idx++;
			for (int j = 0; j < num[idx]; j++)
				ans += '0';
		}
		else
			ans += tmp[i];
	}

	cout << ans;

	return 0;
}