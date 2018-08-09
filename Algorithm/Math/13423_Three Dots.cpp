#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector <int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		
		sort(v.begin(), v.end());
		int cnt = 0;
		for (int i = 0; i < n - 2; i++)
		{
			int k = i + 2;
			for (int j = i + 1; j < n - 1; j++)
			{
				while (k < n && v[k] < v[j] * 2 - v[i]) k++;
				if (k == n) break;
				if (v[k] == v[j] * 2 - v[i]) cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}