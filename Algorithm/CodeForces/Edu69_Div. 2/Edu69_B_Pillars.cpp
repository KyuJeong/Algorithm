#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n;
vi v;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int _max = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (_max < v[i])
		{
			_max = v[i];
			idx = i;
		}
	}

	int l = idx - 1;
	int r = idx + 1;
	_max--;
	for (int i = 1; i < n; i++)
	{
		if (v[l] == _max)
			l--;
		else if (v[r] == _max)
			r++;
		else
		{
			cout << "NO";
			return 0;
		}
		_max--;
	}

	if (_max == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}