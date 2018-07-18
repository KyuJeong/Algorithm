#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int tmp;
	int arr[1001];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		if (arr[i] & 1)
			cout << arr[i] << " ";
		else
			cout << arr[i] - 1 << " ";
	}

	return 0;
}