#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector <ll> arr;
	int tmp;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	ll sum = 0;
	int cnt = 0;

	for (auto i : arr)
	{
		sum += (cnt * i);
		cnt++;
		if (cnt > k) cnt = k;
	}

	cout << sum;
}