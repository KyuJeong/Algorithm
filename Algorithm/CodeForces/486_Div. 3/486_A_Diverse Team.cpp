#include <bits/stdc++.h>

using namespace std;

bool check[101];

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int cnt = 0;
	vector <int> v;
	int tmp;

	bool flag = false;

	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if (!check[tmp])
		{
			v.push_back(i);
			check[tmp] = true;
		}
		if (v.size() == k)
		{
			flag = true;
			break;
		}
	}

	if (!flag)
		cout << "NO";
	else
	{
		cout << "YES\n";
		for (auto i : v)
			cout << i << " ";
	}

	return 0;
}