#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int k, l;
unordered_map <int, bool> m;
vector <int> v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> k >> l;
	vector <int> v(l);

	for (int i = 0; i < l; i++)
		cin >> v[i];

	for (int i = l - 1; i >= 0; i--)
	{
		if (m[v[i]])
			v[i] = -1;
		else
			m[v[i]] = true;
	}

	int cnt = 0;

	for (auto i : v)
	{
		if (i == -1) continue;

		cout.width(8);
		cout.fill('0');
		cout << i << "\n";
		cnt++;

		if (cnt == k) break;
	}

	return 0;
}