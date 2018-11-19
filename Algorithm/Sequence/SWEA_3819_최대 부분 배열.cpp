#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; test++)
	{
		int n;
		cin >> n;

		vector <int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int ans = v[0];
		int num = max(0, v[0]);
		for (int i = 1; i < n; i++)
		{
			if (num + v[i] >= 0)
			{
				num = num + v[i];
				ans = max(ans, num);
			}
			else
			{
				num = 0;
				ans = max(ans, v[i]);
			}
		}

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}