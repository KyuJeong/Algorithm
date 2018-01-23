#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

int N, C, D;
vector <tuple <int, int, int>> t;
int ans;
vector <bool> v;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> C >> D;
		t.emplace_back( C, D, i );
	}

	sort(t.begin(), t.end());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (get<0>(t[i]) == get<0>(t[j]))
				continue;
			if (get<1>(t[i]) >= get<1>(t[j]))
			{
				int idx = get<2>(t[i]);
				v[idx] = true;
				break;
			}
		}
	}

	sort(t.begin(), t.end(), [](const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
		return make_tuple(get<1>(t1), get<0>(t1)) < make_tuple(get<1>(t2), get<0>(t2));
	});

	for (int i = 0; i < N; i++)
	{
		int idx = get<2>(t[i]);
		if (v[idx])
			continue;
		for (int j = 0; j < i; j++)
		{
			if (get<1>(t[i]) == get<1>(t[j]))
				continue;
			if (get<0>(t[i]) >= get<0>(t[j]))
			{
				v[idx] = true;
				break;
			}
		}
	}

	for (auto i : v)
	{
		if (!i)
			ans++;
	}

	cout << ans;

	return 0;
}