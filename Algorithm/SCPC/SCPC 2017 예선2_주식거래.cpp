#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

#define INF 2e9

int T;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;
		int ans = 0;
		int pre = INF;
		bool up = false;

		int cur;
		for (int i = 0; i < N; i++)
		{
			cin >> cur;
			if (up)
			{
				if (pre > cur)
					up = false;
			}
			else
			{
				if (pre < cur)
				{
					up = true;
					ans += 2;
				}
			}
			pre = cur;
		}

		cout << "Case #" << test << "\n";
		cout << ans << "\n";
	}

	return 0;
}