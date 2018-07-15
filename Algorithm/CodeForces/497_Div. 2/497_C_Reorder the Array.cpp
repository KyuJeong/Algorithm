#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	vector <int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int larger = n - 1;
	int smaller = n - 2;

	int cnt = 0;
	while (smaller >= 0)
	{
		if (v[larger] > v[smaller])
		{
			cnt++;
			larger--;
			smaller--;
		}
		else
			smaller--;
	}

	cout << cnt;

	return 0;
}