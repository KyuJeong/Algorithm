#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;
		int ans = 0;
		vector <int> arr(N);
		vector <bool> is_max(N);
		int cur_max = -1;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			if (cur_max < arr[i])
			{
				cur_max = arr[i];
				is_max[i] = true;
			}
		}

		int cur_min = 1e9;

		for (int i = N - 1; i >= 0; i--)
		{
			if (cur_min > arr[i])
			{
				cur_min = arr[i];
				if (is_max[i])
					ans++;
			}
		}

		cout << "Case #" << test << "\n";
		cout << ans << "\n";
	}

	return 0;
}