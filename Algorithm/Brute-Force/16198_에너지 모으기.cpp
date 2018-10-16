#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v;

int f()
{
	vector <int> arr(n - 2);
	for (int i = 0; i < n - 2; i++)
		arr[i] = i + 1;

	int ret = 0;
	do
	{
		bool del[11] = { false };
		int sum = 0;
		for (int i = 0; i < n - 2; i++)
		{
			int idx = arr[i] - 1;
			while (del[idx--]);
			int a = v[idx + 1];

			idx = arr[i] + 1;
			while (del[idx++]);
			int b = v[idx - 1];

			sum += a * b;
			del[arr[i]] = true;
		}
		ret = max(ret, sum);
	} while (next_permutation(arr.begin(), arr.end()));

	return ret;
}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int idx = 0;
	for (int i = 0; i < n; i++)
		if (v[i] > v[idx]) idx = i;

	cout << f();

	return 0;
}