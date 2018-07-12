#include <bits/stdc++.h>

using namespace std;

int N;
int arr[51];
int a, b;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;
	if (N == 1)
	{
		cout << "A";
		return 0;
	}

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (N == 2)
	{
		if (arr[0] == arr[1])
		{
			cout << arr[0];
			return 0;
		}
		cout << "A";
		return 0;
	}

	if (arr[0] == arr[1])
		a = 1;
	else
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

	b = arr[1] - arr[0] * a;

	int pre;
	for (int i = 2; i < N; i++)
	{
		pre = arr[i - 1] * a + b;
		if (pre != arr[i])
		{
			cout << "B";
			return 0;
		}
	}

	cout << arr[N - 1] * a + b;

	return 0;
}