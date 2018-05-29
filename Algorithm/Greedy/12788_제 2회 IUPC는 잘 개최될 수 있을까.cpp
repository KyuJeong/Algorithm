#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int pen = M * K;

	sort(arr, arr + N);

	int sum = 0;
	int cnt = 1;

	for (int i = N - 1; i >= 0; i--)
	{
		sum += arr[i];
		if (sum >= pen)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
	}

	cout << "STRESS";

	return 0;
}