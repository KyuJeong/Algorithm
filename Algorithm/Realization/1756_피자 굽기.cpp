#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

int D, N;
int oven, pizza;
vi _min;

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> D >> N;
	_min.resize(D + 1);
	_min[0] = 1e9;

	for (int i = 1; i <= D; i++)
	{
		cin >> oven;
		_min[i] = min(_min[i - 1], oven);
	}

	int idx = D;

	for (int i = 1; i <= N; i++)
	{
		cin >> pizza;
		bool find = false;
		for (int j = idx; j > 0; j--)
		{
			if (_min[j] >= pizza)
			{
				idx = j - 1;
				find = true;
				break;
			}
		}
		if (!find)
		{
			cout << "0";
			return 0;
		}
	}

	int ans = idx + 1;

	cout << ans;

	return 0;
}