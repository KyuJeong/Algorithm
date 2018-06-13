#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		if (s[0] == 'P')
			cout << "skipped\n";
		else
		{
			int idx;
			string a, b;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '+')
				{
					idx = i;
					a = s.substr(0, i);
					b = s.substr(i + 1, s.size() - 1);
				}
			}
			cout << stoi(a) + stoi(b) << "\n";
		}
	}

	return 0;
}