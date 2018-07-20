#include <bits/stdc++.h>

using namespace std;

int n;
double arr[100001];
double k;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> k;

	if (n == 1)
	{
		if (arr[1] == k)
			cout << "T";
		else
			cout << "F";
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		double a = arr[i - 1] / (i - 1);
		double b = arr[i] / i;
		if (a > b)
			swap(a, b);
		if (k >= a && k <= b)
		{
			cout << "T";
			return 0;
		}
	}

	cout << "F";

	return 0;
}