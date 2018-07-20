#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string s;
	cin >> s;

	int sec = 0;
	bool pull = true;
	int route = 0;
	for (auto i : s)
	{
		if (sec == 0)
		{
			if (i == 'W')
				sec++;
			else
				route ^= 1;
		}
		else if (sec == 1)
		{
			if (i == 'W')
			{
				sec++;
				break;
			}
			else
				route = 2;
		}
		else
			break;
	}

	if (sec < 2)
	{
		cout << "0";
		return 0;
	}

	if (route == 0)
		cout << "5";
	else if (route == 1)
		cout << "1";
	else
		cout << "6";

	return 0;
}