#include <iostream>
#include <string>

using namespace std;

int N;
int ans;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		bool ch[26] = { false };
		bool flag = true;

		char pre, cur;
		pre = s[0];

		for (int i = 1; i < s.size(); i++)
		{
			cur = s[i];
			if (ch[cur - 'a'])
			{
				flag = false;
				break;
			}
			if (cur != pre)
			{
				ch[pre - 'a'] = true;
				pre = cur;
			}
		}

		if (flag)
			ans++;
	}

	cout << ans;

	return 0;
}