#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
ll arr[200002];
ll sum[200002];
ll rev[200002];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = N; i >= 1; i--)
		rev[i] = rev[i + 1] + arr[i];

	int l = 1;
	int r = N;
	ll _max = 0;

	while (l < r)
	{
		if (sum[l] == rev[r])
		{
			_max = max(_max, sum[l]);
			l++;
			r--;
		}
		else if (sum[l] < rev[r])
			l++;
		else
			r--;
	}
	cout << _max;

	return 0;
}