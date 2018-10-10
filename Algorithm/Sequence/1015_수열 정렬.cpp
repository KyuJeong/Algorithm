#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> v;
vector <pii> p;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first, v[i].second = i;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		p.push_back({ v[i].second, i });

	sort(p.begin(), p.end());

	for (auto i : p)
		cout << i.second << " ";

	return 0;
}