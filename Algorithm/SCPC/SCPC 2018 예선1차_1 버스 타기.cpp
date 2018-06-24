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
		int N, K;
		cin >> N >> K;

		int arr[200001];

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N);

		int ans = 1;
		int ptr = 0;
		int val = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (arr[i] - val <= K)
				ans++;
			else
				val = arr[++ptr];
			if (ans == K + 1)
				break;
		}

		cout << "Case #" << test << "\n";
		cout << ans << "\n";
	}

	return 0;
}