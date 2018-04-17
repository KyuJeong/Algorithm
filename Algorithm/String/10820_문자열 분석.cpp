#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string s;

	while (getline(cin, s))
	{
		int cnt[4] = { 0 };
		int len = s.size();

		for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				cnt[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				cnt[1]++;
			else if (s[i] >= '0' && s[i] <= '9')
				cnt[2]++;
			else
				cnt[3]++;
		}

		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";
	}

	return 0;
}